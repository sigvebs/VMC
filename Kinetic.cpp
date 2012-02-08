/* 
 * File:   Kinetic.cpp
 * Author: sigve
 * 
 * Created on 8. februar 2012, 17:06
 */

#include "Kinetic.h"

Kinetic::Kinetic( int dim, int n_particles, double charge ){
    this->n_particles = n_particles;
    this->dim = dim;
    this->charge = charge;
}

Kinetic::~Kinetic() {
}

