/* 
 * File:   MC_Brute_Force.cpp
 * Author: sigve
 * 
 * Created on 17. februar 2012, 14:43
 */
#include "MC_Brute_Force.h"

MC_Brute_Force::MC_Brute_Force(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum) : QVMC(ht, wf, mc_cycles, idum) {
}

/*******************************************************************
 * 
 * NAME :               mc_sampling( int cycles, double step_length, 
 *                      int& accepted, double& total_energy, 
 *                      double& total_energy_sq)
 *
 * DESCRIPTION :        Coming
 */
void MC_Brute_Force::solve() {
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
 *                      int& accepted, double& energy, 
 *                      double& energy_sq)
 *
 * DESCRIPTION :        Coming
 */
void MC_Brute_Force::mc_sampling(int cycles, double step_length, int& accepted, double& energy, double& energy_sq) {
    double R;
    double delta_e, loc_energy, loc_energy_sq;

    int n_particles = wf->getNParticles();
    int dim = wf->getDim();

    // Initiating variables
    loc_energy = 0;
    loc_energy_sq = 0;
    delta_e = 0;
    accepted = 0;

    // Initial position of the electrons
    mat r_old = zeros(n_particles, dim);
    mat r_new = zeros(n_particles, dim);

    for (int i = 0; i < n_particles; i++)
        for (int j = 0; j < dim; j++)
            r_old(i, j) = r_old(i, j) + step_length * (ran3(&idum) - 0.5);

    r_new = r_old;

    // Evalutating the Quantum Force and Wave Function in the inital position.
    wf->set_r_new(r_old, 0);
    wf->init_slater();
    wf->accept_move();

    //cout << "MC_cycles = " << cycles << endl;
    //cout << "Thermalization = " << thermalization << endl;

    // Monte Carlo cycles
    for (int sample = 0; sample < (cycles + thermalization); sample++) {

        // Looping over all particles.   
        for (int active = 0; active < n_particles; active++) {

            // Calculating new trial position.
            for (int i = 0; i < dim; i++) {
                r_new(active, i) = r_old(active, i) + step_length * (ran3(&idum) - 0.5);
            }
            // Evaluating the Wave Function in r_new.
            wf->set_r_new(r_new, active);
            wf->evaluate_new();

            // Metropolis acceptance test.
            R = wf->get_ratio();
            R = R * R;

            if (ran3(&idum) <= R) {
                r_old = r_new;
                wf->accept_move();

                if (sample > thermalization) {
                    accepted++;
                }
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
 * NAME :               optimal_step_length()
 *
 * DESCRIPTION :        Calulates the optimal step length using
 *                      Newtons method.
 */
double MC_Brute_Force::optimal_step_length() {
    double min, max, tolerance;
    min = 0.01;
    max = 3;
    tolerance = 0.1;

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
double MC_Brute_Force::difference(double step_length) {
    double tmp1, tmp2;
    double tot_energy, tot_energy_sq;
    int accepted, mc_samples_sl;
    //mc_samples_sl = (int) 1e4;
    mc_samples_sl = (int) 1e4/4;
    tot_energy = tot_energy_sq = 0;
    accepted = 0;
    mc_sampling(mc_samples_sl, step_length, accepted, tmp1, tmp2);
    return (double) accepted / mc_samples_sl - 0.5;
}