/* 
 * File:   Kinetic_electron.cpp
 * Author: sigve
 * 
 * Created on 8. februar 2012, 18:49
 */

#include "Kinetic_electron.h"
#include "lib.h"
Kinetic_electron::Kinetic_electron( int dim, int n_particles, double charge): Kinetic( dim, n_particles, charge ){
}

/*******************************************************************
 * 
 * NAME :               evaluate( double* r)
 *
 * DESCRIPTION :        In progress.
 * 
 */
double Kinetic_electron::evaluate( double** r ){
    // the step length and its squared inverse for the second derivative 
#define h 0.001
#define h2 1000000
  int i, j;
  
  double wfminus, wfplus, wfold, e_kinetic;
  double **r_plus, **r_minus;
  
  wfold = wf->evaluate( r );
  // allocate matrices which contain the position of the particles  
  // the function matrix is defined in the progam library 
  r_plus = (double **) matrix( n_particles, dim, sizeof(double));
  r_minus = (double **) matrix( n_particles, dim, sizeof(double));
  for (i = 0; i < n_particles; i++) { 
    for ( j=0; j < dim; j++) {
      r_plus[i][j] = r_minus[i][j] = r[i][j];
    }
  }

  // compute the kinetic energy  
  e_kinetic = 0;
  for (i = 0; i < n_particles; i++) {
    for (j = 0; j < dim; j++) { 
      r_plus[i][j] = r[i][j]+h;
      r_minus[i][j] = r[i][j]-h;
      wfminus = wf->evaluate( r_minus ); 
      wfplus  = wf->evaluate( r_plus); 
    
      e_kinetic -= (wfminus+wfplus-2*wfold);
      r_plus[i][j] = r[i][j];
      r_minus[i][j] = r[i][j];
    }
  }

  // include electron mass and hbar squared and divide by wave function 
  e_kinetic = 0.5*h2*e_kinetic/wfold;
  return e_kinetic;
}

Kinetic_electron::~Kinetic_electron() {
}

