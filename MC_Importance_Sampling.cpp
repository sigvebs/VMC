/* 
 * File:   MC_Importance_Sampling.cpp
 * Author: sigve
 * 
 * Created on 17. februar 2012, 15:20
 */

#include <armadillo>
#include "MC_Importance_Sampling.h"
#include "includes/lib.h"

/*******************************************************************
 * 
 * NAME :               MC_Importance_Sampling(Hamiltonian* ht, 
 *                      Wavefunction* wf, int mc_cycles, long idum) 
 *
 * DESCRIPTION :        Constructor.
 */
MC_Importance_Sampling::MC_Importance_Sampling(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum) : QVMC(ht, wf, mc_cycles, idum) {
    dt = 0.01; // Default time step
    D = 0.5; // Diffusion constant.
};

/*******************************************************************
 * 
 * NAME :               mc_sampling( int cycles, double step_length, 
 *                      int& accepted, double& total_energy, 
 *                      double& total_energy_sq)
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
 * NAME :               IS_sampling( int cycles, double step_length, 
 *                      int& accepted, double& total_energy, 
 *                      double& total_energy_sq)
 *
 * DESCRIPTION :        Importance sampling
 */
void MC_Importance_Sampling::run_importance_sampling(int cycles, int& accepted, double& energy, double& energy_sq) {
    double delta_e, greens_function, R;

    int n_particles = wf->getNParticles();
    int dim = wf->getDim();

    // Initiating variables
    energy = 0;
    energy_sq = 0;
    accepted = 0;

    // Quantum Force.
    mat q_force_old = zeros<mat > (n_particles, dim);
    mat q_force_new = zeros<mat > (n_particles, dim);

    // Initial position of the electrons
    mat r_old = zeros<mat > (n_particles, dim);
    mat r_new = zeros<mat > (n_particles, dim);

    for (int i = 0; i < n_particles; i++)
        for (int j = 0; j < dim; j++)
            r_old(i, j) = gaussian_deviate(&idum) * sqrt(dt);

    r_new = r_old;

    // Evalutating the Quantum Force and Wave Function in the inital position.
    wf->set_r_new(r_old, 0);
    wf->init_slater();
    q_force_old = wf->q_force();
    wf->accept_move();

    // Monte Carlo cycles
    for (int sample = 0; sample < (cycles + thermalization); sample++) {

        // Looping over all particles.   
        for (int active = 0; active < n_particles; active++) {

            // Calculating new trial position.
            for (int i = 0; i < dim; i++) {
                r_new(active, i) = r_old(active, i) + D * q_force_old(active, i) * dt + gaussian_deviate(&idum) * sqrt(dt);
            }
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
                        - q_force_new(active, j)) - (r_new(active, j) - r_old(active, j)));
            }

            greens_function = exp(0.5 * greens_function);

            // If the quantum force is to large we use a brute force step instead.
            if (q_force_new.max() > 20) {
                greens_function = 1;
                // Calculating new trial position.
                for (int i = 0; i < dim; i++) {
                    r_new(active, i) = r_old(active, i) + gaussian_deviate(&idum) * sqrt(dt);
                }
                wf->set_r_new(r_new, active);
                wf->evaluate_new();
                q_force_new = wf->q_force();
            }

            // Metropolis-Hastings acceptance test.
            R = wf->get_ratio();
            R = R * R*greens_function;

            if (ran3(&idum) <= R) {
                r_old = r_new;
                q_force_old = q_force_new;

                wf->accept_move();

                if (sample > thermalization)
                    accepted++;
            } else {
                // If the move is not accepted the position is reset.
                r_new = r_old;
            }

            // Computing the local energy
            if (sample > thermalization) {
                delta_e = ht->get_energy(r_old);
                energy += delta_e;
                energy_sq += delta_e*delta_e;
            }
        } // End p - particles.
    } // End MC cycles.

    // Computing the total energy
    energy = energy / cycles / n_particles;
    energy_sq = energy_sq / cycles / n_particles;
    accepted /= n_particles;

}

/*******************************************************************
 * 
 * NAME :               gaussian_deviate(long * idum) 
 *
 * DESCRIPTION :        Random numbers with gaussian distribution
 * 
 */
double MC_Importance_Sampling::gaussian_deviate(long * idum) {
    static int iset = 0;
    static double gset;
    double fac, rsq, v1, v2;

    if (idum < 0) iset = 0;
    if (iset == 0) {
        do {
            v1 = 2. * ran2(idum) - 1.0;
            v2 = 2. * ran2(idum) - 1.0;
            rsq = v1 * v1 + v2*v2;
        } while (rsq >= 1.0 || rsq == 0.);
        fac = sqrt(-2. * log(rsq) / rsq);
        gset = v1*fac;
        iset = 1;
        return v2*fac;
    } else {
        iset = 0;
        return gset;
    }
}

