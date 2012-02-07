/* 
 * File:   Wavefunction.cpp
 * Author: Sigve
 * 
 * Created on February 4, 2012, 10:55 PM
 */

#include "Wavefunction.h"
#include <math.h>
#include <iostream>

Wavefunction::Wavefunction(int dim, int n_particles, double alpha, double beta, double charge) {
    this->dim = dim;
    this->n_particles = n_particles;
    this->alpha = alpha;
    this->beta = beta;
    this->charge = charge;
}

double Wavefunction::evaluate( double** r ){
  double argument = 0;
  double r_;

  for( int i=0; i<n_particles; i++){
    r_ = 0;
    for( int j=0; j<dim; j++) {
      r_ += pow(r[i][j], 2);
    }
    argument += sqrt( r_ ); 
  }
  // Jastrow Factor - to be implemented on its own
  
  return exp(-alpha*argument);
}

Wavefunction::~Wavefunction() {
}