/* 
 * File:   Hamiltonian.cpp
 * Author: zigg
 * 
 * Created on February 7, 2012, 7:36 PM
 */

#include "Hamiltonian.h"
#include <math.h>

double Hamiltonian::get_energy( double** r){
  double argument;
  double r_12;
  double r_;

  argument = 0;
  for( int i=0; i<n_particles; i++){
    r_ = 0;
    for( int j=0; j<dim; j++) {
      r_ += r[i][j]*r[i][j];
    }
    argument += 1.0/sqrt(r_); 
  }

  // Calculating the distance between two electrons
  r_12 = 0;
  for( int j=0; j<dim; j++) {
    r_12 += (r[0][j] - r[1][j])*(r[0][j] - r[1][j]);
  }
  r_12 = sqrt(r_12);

  return (alpha - 2)*argument + 1.0/r_12 - alpha*alpha;
}

Hamiltonian::Hamiltonian( Wavefunction* wf ) {
    this->wf = wf;    
    this->dim = wf->getDim();
    this->n_particles = wf->getNParticles();
    this->alpha = wf->getAlpha();
    this->beta = wf->getBeta();
    this->charge = wf->getCharge();
}

Hamiltonian::Hamiltonian() {    

}

Hamiltonian::Hamiltonian(const Hamiltonian& orig) {
}

Hamiltonian::~Hamiltonian() {
}

