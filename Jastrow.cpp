/* 
 * File:   Jastrow.cpp
 * Author: sigve
 * 
 * Created on 29. februar 2012, 17:12
 */

#include "Jastrow.h"

/*******************************************************************
 * 
 * NAME :               Jastrow( double** r )
 *
 * DESCRIPTION :        Constructor.
 * 
 */
Jastrow::Jastrow(int dim, int n_particles, double beta) {
    this->dim = dim;
    this->n_particles = n_particles;
    this->beta = beta;
}