/* 
 * File:   Helium.cpp
 * Author: sigve
 * 
 * Created on 5. februar 2012, 11:03
 */
#include <math.h>
#include "Helium.h"
#include <iostream.h>

double Helium::evaluate( double** r ){
  double argument = 0;
  double r_;

  for( int i=0; i<n_particles; i++){
    r_ = 0;
    for( int j=0; j<dim; j++) {
      r_ += r[i][j]*r[i][j];
    }
    argument += sqrt( r_ ); 
  }
  return exp(-alpha*argument);
}

double Helium::get_energy( double** r){
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

  // calculating the distance between two electrons
  r_12 = 0;
  for( int j=0; j<dim; j++) {
    r_12 += (r[0][j] - r[1][j])*(r[0][j] - r[1][j]);
  }
  r_12 = sqrt(r_12);

  return (alpha - 2)*argument + 1.0/r_12 - alpha*alpha;
}

/* Constructors */
Helium::Helium() {
}

Helium::Helium(int d, int n_p, double alpha_, double beta_):
Wavefunction(d, n_p, alpha_, beta_){

}

Helium::Helium(const Helium& orig) {
}

Helium::~Helium() {
}

