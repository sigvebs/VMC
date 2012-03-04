/* 
 * File:   Harmonic_osc.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 09:03
 */

#include "QD_Harmonic_osc.h"

QD_Harmonic_osc::QD_Harmonic_osc(int dim, int n_particles, double w) : w(w), Potential(dim, n_particles) {
}

double QD_Harmonic_osc::evaluate(mat r) {
    double potential = 0;

    for (int i = 0; i < n_particles; i++) {
        potential += dot(r.row(i), r.row(i));
    }

    return 0.5 * w * w*potential;
}
