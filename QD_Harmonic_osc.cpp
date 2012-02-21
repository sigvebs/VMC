/* 
 * File:   Harmonic_osc.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 09:03
 */

#include "QD_Harmonic_osc.h"

QD_Harmonic_osc::QD_Harmonic_osc(int dim, int n_particles, double w) : Potential(dim, n_particles) {
    this->w = w;
}

QD_Harmonic_osc::~QD_Harmonic_osc() {
}

double QD_Harmonic_osc::evaluate(double** r) {
    double r_single_particle;
    double e_potential = 0;

    for (int i = 0; i < n_particles; i++) {
        r_single_particle = 0;
        for (int j = 0; j < dim; j++) {
            r_single_particle += r[i][j] * r[i][j];
        }
        e_potential += r_single_particle;
    }

    return 0.5 * w * w*e_potential;
}
