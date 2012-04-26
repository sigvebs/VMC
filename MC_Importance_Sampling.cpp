/* 
 * File:   MC_Importance_Sampling.cpp
 * Author: sigve
 * 
 * Created on 17. februar 2012, 15:20
 */

#include <armadillo>
#include "MC_Importance_Sampling.h"
#include "includes/lib.h"
#include "includes/ini.h"

#include "Gaussian Random Variables/ziggurat.hpp"
#include "Gaussian Random Variables/ziggurat.cpp"
#include "Gaussian Random Variables/zignor.h"
#include "Gaussian Random Variables/zignor.c"
#include "Gaussian Random Variables/zigrandom.h"
#include "Gaussian Random Variables/zigrandom.c"

// For blocking
#include <iostream>
#include <fstream>
#include <string.h>
#include <mpi.h>
#include "defines.h"

/*******************************************************************
 * 
 * NAME :               MC_Importance_Sampling(Hamiltonian* ht, 
 *                      Wavefunction* wf, int mc_cycles, long idum) 
 *
 * DESCRIPTION :        Constructor.
 */
MC_Importance_Sampling::MC_Importance_Sampling(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum) : QVMC(ht, wf, mc_cycles, idum) {
    /*
    ini reader("QD.ini");
    dt = reader.GetDouble("IS", "dt"); // Default time step
    D = reader.GetDouble("IS", "D"); // Diffusion constant.
     */
    dt = 0.02;
    D = 0.5;
};

/*******************************************************************
 * 
 * NAME :               solve()
 *
 * DESCRIPTION :        Coming
 */
void MC_Importance_Sampling::solve() {
    double energy, energy_sq;
    int accepted;

    run_importance_sampling(mc_cycles, accepted, energy, energy_sq);

    // Storing results
    this->energy = energy;
    this->energy_sq = energy_sq;
    this->accepted = accepted;
}

/*******************************************************************
 * 
 * NAME :               run_importance_sampling(int cycles, int& accepted, 
 *                                      double& energy, double& energy_sq)
 *
 * DESCRIPTION :        Importance sampling
 */
void MC_Importance_Sampling::run_importance_sampling(int cycles, int& accepted, double& energy, double& energy_sq) {
    int dum = (int) idum;
    RanNormalSetSeedZigVec(&dum, 200);

    // Special case for blocking. We need the rank when writing to file.
#if BLOCKING
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    ostringstream filename;
    filename << "Blocking/files/blocking_" << my_rank << ".dat";
    ofstream blockfile(filename.str().c_str(), ios::out | ios::binary);
#endif
    double delta_e, greens_function, R;
    int n_particles = wf->getNParticles();
    int dim = wf->getDim();

    // Initiating variables
    energy = 0;
    energy_sq = 0;
    accepted = 0;
    delta_e = 0;

    // Quantum Force.
    mat q_force_old = zeros(n_particles, dim);
    mat q_force_new = zeros(n_particles, dim);

    // Initial position of the electrons
    mat r_old = randn(n_particles, dim) * sqrt(dt);
    mat r_new = r_old;

    // Evalutating the Quantum Force and Wave Function in the inital position.
    wf->set_r_new(r_old, 0);
    wf->init_slater();
    q_force_old = wf->q_force();
    wf->accept_move();
    
    // Monte Carlo cycles
    for (int sample = 0; sample < (cycles + thermalization); sample++) {

        // Looping over all particles.   
        for (int active = 0; active < n_particles; active++) {

            // Using the quantum force to calculate a new position.
            for (int i = 0; i < dim; i++)
                r_new(active, i) = r_old(active, i) + D * q_force_old(active, i) * dt + DRanNormalZigVec() * sqrt(dt);

            // Evaluating the Wave Function in r_new.
            wf->set_r_new(r_new, active);
            wf->evaluate_new();

            // Updating the quantum force.
            q_force_new = wf->q_force();

            // Calculating the ratio between the Green's functions.     
            greens_function = 0;
            for (int j = 0; j < dim; j++) {
                greens_function += (q_force_old(active, j) + q_force_new(active, j))
                        * (D * dt * 0.5 * (q_force_old(active, j)
                        - q_force_new(active, j)) - r_new(active, j) + r_old(active, j));
            }

            greens_function = exp(0.5 * greens_function);

            // Metropolis-Hastings acceptance test.
            R = wf->get_ratio();
            R = R * R *greens_function;

            if (ran3(&idum) <= R) {
                r_old = r_new;
                q_force_old = q_force_new;

                wf->accept_move();

                if (sample > thermalization) {
                    accepted++;
                    delta_e = ht->get_energy(r_old);
                }
            } else {
                // If the move is not accepted the position and quantum force is reset.
                r_new = r_old;
                q_force_new = q_force_old;
            }

            // Sampling the energy.
            if (sample > thermalization) {
                energy += delta_e;
                energy_sq += delta_e*delta_e;
#if BLOCKING
                blockfile.write((char*) &delta_e, sizeof (double));
#endif
            }
        }
    } // End MC cycles.

    // Scaling the results.
    energy = energy / cycles / n_particles;
    energy_sq = energy_sq / cycles / n_particles;
    accepted /= n_particles;

#if BLOCKING
    blockfile.close();
#endif
}