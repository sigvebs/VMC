/* 
 * File:   Interaction.cpp
 * Author: sigve
 * 
 * Created on 8. februar 2012, 17:07
 */

#include "Interaction.h"

Interaction::Interaction( int dim, int n_particles,  double charge ){
    this->n_particles = n_particles;
    this->dim = dim;
    this->charge = charge;
}

Interaction::Interaction(const Interaction& orig) {
}

Interaction::~Interaction() {
}

