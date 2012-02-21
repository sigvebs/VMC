/* 
 * File:   qd_wavefunction.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 09:26
 */

#include "QD_wavefunction.h"
#include <math.h>
#include "lib.h"

/*******************************************************************
 *
 * NAME :               QD_wavefunction( double** r)
 *
 * DESCRIPTION :        Constructor
 *
 */
QD_wavefunction::QD_wavefunction(int dim, int n_particles, double alpha, double beta, double w, bool jastrow) : Wavefunction(dim, n_particles, alpha, beta, jastrow) {
    this->w = w;
}

QD_wavefunction::~QD_wavefunction() {
}

/*******************************************************************
 * 
 * NAME :               evaluate( double** r)
 *
 * DESCRIPTION :        Returns the value of the total WF evaluated in r. 
 * 
 */
double QD_wavefunction::evaluate(double** r) {
    double psi;
    psi = eval_simple(r);

    if (jastrow) {
        psi *= eval_jastrow(r);
    }

    return psi;
}

/*******************************************************************
 * 
 * NAME :               eval_simple( double** r)
 *
 * DESCRIPTION :        Evaluates the 'simple' wavefunction at the coordinate r.
 * 
 */
double QD_wavefunction::eval_simple(double** r) {
    double argument = 0;
    double r_;

    for (int i = 0; i < n_particles; i++) {
        r_ = 0;
        for (int j = 0; j < dim; j++) {
            r_ += r[i][j] * r[i][j];
        }
        argument += r_;
    }

    return exp(-0.5 * alpha * w * argument);
}

/*******************************************************************
 * 
 * NAME :               eval_jastrow( double** r)
 *
 * DESCRIPTION :        Evaluates the Jastrow function at the coordinate r.
 * 
 */
double QD_wavefunction::eval_jastrow(double** r) {
    double r_12;

    r_12 = 0;
    for (int j = 0; j < dim; j++) {
        r_12 += pow(r[0][j] - r[1][j], 2);
    }

    r_12 = sqrt(r_12);
    return exp(r_12 / ((1 + beta * r_12)));
}

/**
 * q_force returns the quantum force of the particle.
 * 
 * @param r position vector
 * @param particle_number active particle
 * @param component vector component
 * @return 
 */
void QD_wavefunction::q_force(double** r, double** q_force) {
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
                q_f += get_gradient_C(r, i, j);
            q_force[i][j] = 2 * q_f;
#endif
        }
    }

    free_matrix((void**) r_plus);
    free_matrix((void**) r_minus);
}

/*******************************************************************
 * 
 * NAME :               get_simple_gradient( double** r, int particle_number )
 *
 * DESCRIPTION :        Evaluates the simple Wavefunction's gradient in r
 * 
 */
double QD_wavefunction::get_simple_gradient(double** r, int active, int component) {
    return -w * alpha * r[active][component];
}

/*******************************************************************
 * 
 * NAME :               get_gradient_C( double** r, int particle_number )
 *
 * DESCRIPTION :        Evaluates the Jasrow Wavefunction's gradient in r
 * 
 */
double QD_wavefunction::get_gradient_C(double** r, int active, int component) {
    double gradient;
    double r12 = 0;

    gradient = 0;

    for (int p = 0; p < n_particles; p++) {
        if (p != active) {
            for (int i = 0; i < dim; i++) {
                r12 += (r[active][i] - r[p][i])*(r[active][i] - r[p][i]);
            }
            r12 = sqrt(r12);
            gradient += (r[active][component] - r[p][component]) / (r12 * (1 + beta * r12)*(1 + beta * r12));
        }
    }
    return gradient;
}