/* 
 * File:   QD_MC_Importance_Sampling.cpp
 * Author: sigve
 * 
 * Created on 17. februar 2012, 15:20
 */

#include "QD_MC_Importance_Sampling.h"
#include "lib.h"

/*******************************************************************
 * 
 * NAME :               QD_MC_Importance_Sampling(Hamiltonian* ht, 
 *                      Wavefunction* wf, int mc_cycles, long idum) 
 *
 * DESCRIPTION :        Constructor.
 */
QD_MC_Importance_Sampling::QD_MC_Importance_Sampling(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum) : QVMC(ht, wf, mc_cycles, idum) {
    dt = 0.01; // Default time step
    D = 0.5; // Diffusion constant.
};

QD_MC_Importance_Sampling::~QD_MC_Importance_Sampling() {
}

/*******************************************************************
 * 
 * NAME :               mc_sampling( int cycles, double step_length, 
 *                      int& accepted, double& total_energy, 
 *                      double& total_energy_sq)
 *
 * DESCRIPTION :        Coming
 */
void QD_MC_Importance_Sampling::solve() {
    double energy, energy_sq;
    int accepted;

    ic_sampling(mc_cycles, accepted, energy, energy_sq);

    // Storing results
    this->energy = energy;
    this->energy_sq = energy_sq;
    this->accepted = accepted;
}

/*******************************************************************
 * 
 * NAME :               ic_sampling( int cycles, double step_length, 
 *                      int& accepted, double& total_energy, 
 *                      double& total_energy_sq)
 *
 * DESCRIPTION :        Importance sampling
 */
void QD_MC_Importance_Sampling::ic_sampling(int cycles, int& accepted, double& energy, double& energy_sq) {
    double wf_old, wf_new, delta_e, greens_function;

    int n_particles = wf->getNParticles();
    int dim = wf->getDim();

    // Initiating variables
    energy = energy_sq = accepted = 0;

    // Quantum Force.
    double **q_force_old, **q_force_new;
    q_force_old = (double **) matrix(n_particles, dim, sizeof (double));
    q_force_new = (double **) matrix(n_particles, dim, sizeof (double));

    // Initial position of the electrons
    double **r_old, **r_new;
    r_old = (double **) matrix(n_particles, dim, sizeof (double));
    r_new = (double **) matrix(n_particles, dim, sizeof (double));

    for (int i = 0; i < n_particles; i++) {
        for (int j = 0; j < dim; j++) {
            r_old[i][j] = gaussian_deviate(&idum) * sqrt(dt);
            r_new[i][j] = r_old[i][j];
        }
    }

    // Evalutating the Quantum Force and Wave Function in the inital position.
    wf_old = wf->evaluate(r_old);
    wf->q_force(r_old, q_force_old);

    // Monte Carlo cycles
    for (int sample = 0; sample < (cycles + thermalization); sample++) {

        // Looping over all particles.   
        for (int active = 0; active < n_particles; active++) {

            // Calculating new trial position.
            for (int j = 0; j < dim; j++) {
                r_new[active][j] = r_old[active][j] + D * q_force_old[active][j] * dt + gaussian_deviate(&idum) * sqrt(dt);
            }
            // Updating the quantum force.
            wf->q_force(r_new, q_force_new);

            // Calculating the ratio between the Green's functions.
            greens_function = 0;
            for (int j = 0; j < dim; j++) {
                greens_function += (q_force_old[active][j] + q_force_new[active][j])
                        * (D * dt * 0.5 * (q_force_old[active][j] - q_force_new[active][j]) - (r_new[active][j] - r_old[active][j]));
            }
            greens_function = exp(0.5 * greens_function);

            // Evaluating the Wave Function in r_new.
            wf_new = wf->evaluate(r_new);

            // Metropolis-Hastings acceptance test .
            if (ran2(&idum) <= greens_function * wf_new * wf_new / wf_old / wf_old) {
                // Storing the accepted values.
                for (int i = 0; i < n_particles; i++) {
                    for (int j = 0; j < dim; j++) {
                        r_old[i][j] = r_new[i][j];
                        q_force_old[i][j] = q_force_new[i][j];
                    }
                }
                wf_old = wf_new;
                if (sample > thermalization) {
                    accepted++;
                }
            } else {
                // If the move is not accepted the position is reset.
                for (int i = 0; i < n_particles; i++) {
                    for (int j = 0; j < dim; j++)
                        r_new[i][j] = r_old[i][j];
                }
            }

            // Computing the local energy
            if (sample > thermalization) {
                delta_e = ht->get_energy(r_old);
                energy += delta_e;
                energy_sq += delta_e*delta_e;
            }
        }
    }

    // Computing the total energy
    energy = energy / cycles / n_particles;
    energy_sq = energy_sq / cycles / n_particles;
    accepted /= n_particles;

    // Freeing memory
    free_matrix((void**) r_old);
    free_matrix((void**) r_new);
    free_matrix((void**) q_force_old);
    free_matrix((void**) q_force_new);
}

/*******************************************************************
 * 
 * NAME :               gaussian_deviate(long * idum) 
 *
 * DESCRIPTION :        random numbers with gaussian distribution
 * 
 */
double QD_MC_Importance_Sampling::gaussian_deviate(long * idum) {
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

