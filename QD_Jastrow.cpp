/* 
 * File:   QD_Jastrow.cpp
 * Author: sigve
 * 
 * Created on 29. februar 2012, 17:29
 */

#include "QD_Jastrow.h"
#include <math.h>

QD_Jastrow::QD_Jastrow(int dim, int n_particles, double beta): Jastrow( dim, n_particles, beta) {
}

/*******************************************************************
 * 
 * NAME :               evaluate( double** r )
 *
 * DESCRIPTION :        Evaluates the Jasrow Wavefunction in r
 * 
 */
double QD_Jastrow::evaluate(double** r){
    double r_12;

    r_12 = 0;
    for (int j = 0; j < dim; j++) {
        r_12 += pow(r[0][j] - r[1][j], 2);
    }

    r_12 = sqrt(r_12);
    return exp(r_12 / ((1 + beta * r_12)));
}

/*******************************************************************
 * 
 * NAME :               get_gradient( double** r, int particle_number )
 *
 * DESCRIPTION :        Evaluates the Jasrow Wavefunction's gradient in r
 * 
 */
double QD_Jastrow::get_gradient(double** r, int active, int component) {
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