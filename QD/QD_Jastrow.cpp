/* 
 * File:   QD_Jastrow.cpp
 * Author: sigve
 * 
 * Created on 29. februar 2012, 17:29
 */

#include "QD_Jastrow.h"
#include <math.h>

QD_Jastrow::QD_Jastrow(int dim, int n_particles, double beta) : Jastrow(dim, n_particles, beta) {

    // Initiating a matrix with all the spin dependant a-values.
    a = zeros <mat > (n_particles, n_particles);

    for (int i = 0; i < n_particles; i++) {
        for (int j = 0; j < n_particles; j++) {

            if (i == j)
                a(i, j) = 0;
            else if (i < n_particles / 2 && j >= n_particles / 2 || i >= n_particles / 2 && j < n_particles / 2)
                a(i, j) = 1.0;
            else
                a(i, j) = 1.0 / 3.0;
        }
    }
}

/*******************************************************************
 * 
 * NAME :               evaluate(mat r)
 *
 * DESCRIPTION :        Evaluates the Jasrow Wavefunction in r
 * 
 */
double QD_Jastrow::evaluate(mat r) {
    double r_norm;
    double value = 0;

    // ------------ Move the loop into the WF ------------
    for (int i = 0; i < n_particles; i++) {
        for (int j = i + 1; j < n_particles; j++) {

            r_norm = 0;
            for (int d = 0; d < dim; d++) {
                r_norm += (r(i, d) - r(j, d))*(r(i, d) - r(j, d));
            }
            r_norm = sqrt(r_norm);
            value += a(i, j) * r_norm / ((1 + beta * r_norm));
        }
    }

    // The exp() is now added in the WF.
    return value;
}

/*******************************************************************
 * 
 * NAME :               get_laplacian(mat r)
 *
 * DESCRIPTION :        Evaluates the Jasrow Wavefunction's 
 *                      Laplaicaian at all coordinates.
 * 
 */
double QD_Jastrow::get_laplacian(mat r, int i) {
    double r_ki;
    double sum = 0;

    // Before i
    for (int k = 0; k < i; k++) {
        r_ki = norm(r.row(k) - r.row(i), 2);
        sum += a(k, i)*(1 - beta * r_ki) / r_ki / pow((1 + beta * r_ki), 3);
    }

    // After i
    for (int k = i + 1; k < n_particles; k++) {
        r_ki = norm(r.row(k) - r.row(i), 2);
        sum += a(k, i)*(1 - beta * r_ki) / r_ki / pow((1 + beta * r_ki), 3);
    }

    double Gj_sq = dot(gradient, gradient);
    return Gj_sq + sum;
}

/*******************************************************************
 * 
 * NAME :               compute_gradient(mat r)
 *
 * DESCRIPTION :        Computes the total Jasrow Wavefunction's 
 *                      gradient in r.
 * 
 */
void QD_Jastrow::compute_gradient(mat r, int i) {
    double r_ki;
    gradient = zeros(1, dim);

    // Before i
    for (int k = 0; k < i; k++) {
        r_ki = norm(r.row(k) - r.row(i), 2);
        gradient += a(k, i) / r_ki / pow((1 + beta * r_ki), 2)*(r.row(i) - r.row(k));
    }

    // After i
    for (int k = i + 1; k < n_particles; k++) {
        r_ki = norm(r.row(k) - r.row(i), 2);
        gradient += a(k, i) / r_ki / pow((1 + beta * r_ki), 2)*(r.row(i) - r.row(k));
    }
}