/* 
 * File:   QD_MC_Brute_Force.cpp
 * Author: sigve
 * 
 * Created on 17. februar 2012, 14:43
 */

#include "QD_MC_Brute_Force.h"
#include "lib.h"

QD_MC_Brute_Force::QD_MC_Brute_Force(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum) : QVMC(ht, wf, mc_cycles, idum) {
}

QD_MC_Brute_Force::~QD_MC_Brute_Force() {
}

/*******************************************************************
 * 
 * NAME :               mc_sampling( int cycles, double step_length, 
 *                      int& accepted, double& total_energy, 
 *                      double& total_energy_sq)
 *
 * DESCRIPTION :        Coming
 */
void QD_MC_Brute_Force::solve() {
    double step_length, energy, energy_sq;
    int accepted;
    energy = 0;
    energy_sq = 0;
    step_length = optimal_step_length();
    mc_sampling(mc_cycles, step_length, accepted, energy, energy_sq);

    // Storing results
    this->energy = energy;
    this->energy_sq = energy_sq;
    this->step_length = step_length;
    this->accepted = accepted;
}

/*******************************************************************
 * 
 * NAME :               mc_sampling( int cycles, double step_length, 
 *                      int& accepted, double& total_energy, 
 *                      double& total_energy_sq)
 *
 * DESCRIPTION :        Coming
 */
void QD_MC_Brute_Force::mc_sampling(int cycles, double step_length, int& accepted, double& total_energy, double& total_energy_sq) {
    int i, j;
    double wf_old, wf_new;
    double delta_e, loc_energy, loc_energy_sq;

    int n_particles = wf->getNParticles();
    int dim = wf->getDim();

    // Initiating variables
    loc_energy = loc_energy_sq = delta_e = 0;
    accepted = 0;

    // Initial position of the electrons
    double **r_old, **r_new;
    r_old = (double **) matrix(n_particles, dim, sizeof (double));
    r_new = (double **) matrix(n_particles, dim, sizeof (double));

    for (i = 0; i < n_particles; i++) {
        for (j = 0; j < dim; j++) {
            r_new[i][j] = 0;
            r_old[i][j] = step_length * (ran3(&idum) - 0.5);
        }
    }

    wf_old = wf->evaluate(r_old);

    // Monte Carlo cycles
    for (int sample = 0; sample < (cycles + thermalization); sample++) {

        // Changes the position of the electrons
#if 0 // Moving one particle at the time
        int active = sample % (n_particles);

        for (j = 0; j < dim; j++) {
            r_new[active][j] = r_old[active][j] + step_length * (ran2(&idum) - 0.5);
        }
#else // Moving both particles
        for (i = 0; i < n_particles; i++) {
            for (j = 0; j < dim; j++) {
                r_new[i][j] = r_old[i][j] + step_length * (ran3(&idum) - 0.5);
            }
        }
#endif

        wf_new = wf->evaluate(r_new);

        // Metropolis test 
        if (ran2(&idum) <= pow(wf_new, 2) / pow(wf_old, 2)) {
            for (i = 0; i < n_particles; i++) {
                for (j = 0; j < dim; j++)
                    r_old[i][j] = r_new[i][j];
            }
            wf_old = wf_new;
            accepted++;
        }

        // Computing the local energy
        if (sample > thermalization) {
            delta_e = ht->get_energy(r_old);
            loc_energy += delta_e;
            loc_energy_sq += delta_e*delta_e;
        }
    }

    // Computing the total energy
    total_energy = loc_energy / cycles;
    total_energy_sq = loc_energy_sq / cycles - total_energy*total_energy;

    // Freeing memory
    free_matrix((void**) r_old);
    free_matrix((void**) r_new);
}

/*******************************************************************
 * 
 * NAME :               optimal_step_length()
 *
 * DESCRIPTION :        Coming
 */
double QD_MC_Brute_Force::optimal_step_length() {
    double min, max, tolerance;
    min = 0.01;
    max = 4;
    tolerance = 0.01;

    while ((max - min) > tolerance) {
        if (difference(min) * difference((min + max) / 2) < 0)
            max = (min + max) / 2;
        else
            min = (min + max) / 2;
    }
    return (min + max) / 2;
}

/*******************************************************************
 * 
 * NAME :               difference( double step_length )
 *
 * DESCRIPTION :        Coming
 */
double QD_MC_Brute_Force::difference(double step_length) {
    double tmp1, tmp2;
    double tot_energy, tot_energy_sq;
    int accepted, mc_samples_sl;
    mc_samples_sl = (int) 1e5;
    tot_energy = tot_energy_sq = 0;
    accepted = 0;
    mc_sampling(mc_samples_sl, step_length, accepted, tmp1, tmp2);
    return (double) accepted / mc_samples_sl - 0.5;
}