/* 
 * File:   Wavefunction.cpp
 * Author: Sigve
 * 
 * Created on February 4, 2012, 10:55 PM
 */

#include "Wavefunction.h"
#include <math.h>
#include <iostream>
#include "QD_Jastrow.h"
#include "lib.h"

/*******************************************************************
 * 
 * NAME :               Wavefunction(int dim, int n_particles, double alpha, 
 *                      double beta, double charge)
 *
 * DESCRIPTION :        Constructor
 * 
 */
Wavefunction::Wavefunction(int dim, int n_particles, double alpha, double beta, bool jastrow) {
    jas = new QD_Jastrow(dim, n_particles, beta);
    this->dim = dim;
    this->n_particles = n_particles;
    this->alpha = alpha;
    this->beta = beta;
    this->jastrow = jastrow;
}

/*******************************************************************
 * 
 * NAME :               Wavefunction(int dim, int n_particles, double alpha, 
 *                      double beta, double charge)
 *
 * DESCRIPTION :        Constructor
 * 
 */
double Wavefunction::evaluate(double** r) {
    double psi;
    psi = eval_simple(r);

    if (jastrow) {
        psi *= jas->evaluate(r);
    }

    return psi;
}

/**
 * q_force returns the quantum force of the particle.
 * 
 * @param r position vector
 * @param particle_number active particle
 * @param component vector component
 * @return 
 */
void Wavefunction::q_force(double** r, double** q_force) {
    double q_f;
    double h;
    double **r_plus;
    double **r_minus;
    h = 0.001;

    r_plus = (double **) matrix(n_particles, dim, sizeof (double));
    r_minus = (double **) matrix(n_particles, dim, sizeof (double));

    // Initiating r+ and r-.
    for (int i = 0; i < n_particles; i++) {
        for (int j = 0; j < dim; j++) {
            r_plus[i][j] = r[i][j];
            r_minus[i][j] = r[i][j];
        }
    }

    // Calculating the Quantum Force numerically.
    for (int i = 0; i < n_particles; i++) {
        for (int j = 0; j < dim; j++) {
#if 0 //Numerical solution.
            r_plus[i][j] += h;
            r_minus[i][j] -= h;
            q_force[i][j] = 2 * (evaluate(r_plus) - evaluate(r_minus)) / (2 * h * evaluate(r));
            r_plus[i][j] = r[i][j];
            r_minus[i][j] = r[i][j];
#else // Anlytical solution.
            q_f = get_simple_gradient(r, i, j);
            if (jastrow)
                q_f += jas->get_gradient(r, i, j);
            q_force[i][j] = 2 * q_f;
#endif
        }
    }

    free_matrix((void**) r_plus);
    free_matrix((void**) r_minus);
}