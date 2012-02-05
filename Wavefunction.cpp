/* 
 * File:   Wavefunction.cpp
 * Author: Sigve
 * 
 * Created on February 4, 2012, 10:55 PM
 */

#include "Wavefunction.h"

Wavefunction::Wavefunction() {
}

Wavefunction::Wavefunction(int d, int n_p, double alpha_, double beta_) {
    dim = d;
    n_particles = n_p;
    alpha = alpha_;
    beta = beta_;
}

Wavefunction::Wavefunction(const Wavefunction& orig) {
}

Wavefunction::~Wavefunction() {
}

