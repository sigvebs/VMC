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
Wavefunction::Wavefunction(int dim, int n_particles, double alpha, double beta ) {
    this->dim = dim;
    this->n_particles = n_particles;
    this->alpha = alpha;
    this->beta = beta;
    jastrow = true;
}

/*******************************************************************
 * 
 * NAME :               evaluate( double** r)
 *
 * DESCRIPTION :        Evaluates the wavefunction at the coordinate r.
 * 
 */
/*
double Wavefunction::evaluate( double** r ){
    double psi;
    psi = eval_simple(r);
    
    if(jastrow)
        psi *= eval_jastrow(r);
    
    return psi;
}
*/
/*******************************************************************
 * 
 * NAME :               eval_simple( double** r)
 *
 * DESCRIPTION :        Evaluates the 'simple' wavefunction at the coordinate r.
 * 
 */
/*
double Wavefunction::eval_simple( double** r ){
  double argument = 0;
  double r_;

  for( int i=0; i<n_particles; i++){
    r_ = 0;
    for( int j=0; j<dim; j++) {
      r_ += pow(r[i][j], 2);
    }
    argument += sqrt( r_ ); 
  }
  
  return exp(-alpha*argument);
}
*/
/*******************************************************************
 * 
 * NAME :               eval_jastrow( double** r)
 *
 * DESCRIPTION :        Evaluates the Jastrow function at the coordinate r.
 * 
 */
/*
double Wavefunction::eval_jastrow( double** r ){
  double r_12;

  r_12 = 0;
  for( int j=0; j<dim; j++) {
    r_12 += pow(r[0][j] - r[1][j], 2);
  }
  r_12 = sqrt(r_12);
  return exp(r_12/(2*(1+beta*r_12)));
}
*/
Wavefunction::~Wavefunction() {
}