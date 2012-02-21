/* 
 * File:   Wavefunction.cpp
 * Author: Sigve
 * 
 * Created on February 4, 2012, 10:55 PM
 */

#include "Wavefunction.h"
#include <math.h>
#include <iostream>

/*******************************************************************
 * 
 * NAME :               Wavefunction(int dim, int n_particles, double alpha, 
 *                      double beta, double charge)
 *
 * DESCRIPTION :        Constructor
 * 
 */
Wavefunction::Wavefunction(int dim, int n_particles, double alpha, double beta, bool jastrow ) {
    this->dim = dim;
    this->n_particles = n_particles;
    this->alpha = alpha;
    this->beta = beta;
    this->jastrow = jastrow;
}

Wavefunction::~Wavefunction() {
}