/* 
 * File:   qd_wavefunction.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 09:26
 */

#include "QD_wavefunction.h"
#include <math.h>

QD_wavefunction::QD_wavefunction(int dim, int n_particles, double alpha, double beta, double w):Wavefunction(dim, n_particles, alpha, beta ) {
    this->w = w;
}

QD_wavefunction::~QD_wavefunction() {
}

/*******************************************************************
 * 
 * NAME :               evaluate( double** r)
 *
 * DESCRIPTION :        Returns the value of the total WF evaluated in r. 
 * 
 */
double QD_wavefunction::evaluate( double** r ){
    double psi;
    psi = eval_simple(r);
    
    if(jastrow)
        psi *= eval_jastrow(r);
    
    return psi;
}

/*******************************************************************
 * 
 * NAME :               eval_simple( double** r)
 *
 * DESCRIPTION :        Evaluates the 'simple' wavefunction at the coordinate r.
 * 
 */
double QD_wavefunction::eval_simple( double** r ){
  double argument = 0;
  double r_;

  for( int i=0; i<n_particles; i++){
    r_ = 0;
    for( int j=0; j<dim; j++) {
      r_ += pow(r[i][j], 2);
    }
    argument += r_; 
  }
  
  return exp(-0.5*alpha*w*argument);
}

/*******************************************************************
 * 
 * NAME :               eval_jastrow( double** r)
 *
 * DESCRIPTION :        Evaluates the Jastrow function at the coordinate r.
 * 
 */
double QD_wavefunction::eval_jastrow( double** r ){
  double r_12;

  r_12 = 0;
  for( int j=0; j<dim; j++) {
    r_12 += pow(r[0][j] - r[1][j], 2);
  }
  
  r_12 = sqrt(r_12);
  return exp(r_12/((1+beta*r_12)));
}
