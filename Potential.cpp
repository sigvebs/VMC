/* 
 * File:   Potential.cpp 
 * Author: Sigve
 * 
 * Created on February 4, 2012, 10:56 PM
 */

#include "Potential.h"

Potential::Potential( int dim, int n_particles,  double charge ){
    this->n_particles = n_particles;
    this->dim = dim;
    this->charge = charge;
}

Potential::Potential(const Potential& orig) {
}

Potential::~Potential() {
}

