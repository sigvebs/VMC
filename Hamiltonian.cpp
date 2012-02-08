/* 
 * File:   Hamiltonian.cpp
 * Author: zigg
 * 
 * Created on February 7, 2012, 7:36 PM
 */

#include "Hamiltonian.h"
#include <math.h>
#include "lib.h"
#include <iostream>

/*******************************************************************
 * 
 * NAME :               get_energy( double** r)
 *
 * DESCRIPTION :        Return the local energy at the coordinate r.
 * 
 */
double Hamiltonian::get_energy( double** r){
    double energy = 0;
    if( analytic_energy )
        energy = get_analytic_energy( r );
    else
        energy = get_numerical_energy( r );
              
    return energy;
}

/*******************************************************************
 * 
 * NAME :               get_analytic_energy( double** r)
 *
 * DESCRIPTION :        Return the the analytic solution to the 
 *                      energy at the coordinate r.
 * 
 */
double Hamiltonian::get_analytic_energy( double** r){
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

/*******************************************************************
 * 
 * NAME :               Hamiltonian( Wavefunction* wf )
 *
 * DESCRIPTION :        Constructor 
 * 
 */
Hamiltonian::Hamiltonian( Wavefunction* wf ) {
    this->wf            = wf;    
    this->dim           = wf->getDim();
    this->n_particles   = wf->getNParticles();
    this->alpha         = wf->getAlpha();
    this->beta          = wf->getBeta();
    this->charge        = wf->getCharge();
    analytic_energy     = false; // More later
}

/*******************************************************************
 * 
 * NAME :               get_numerical_energy( double** r )
 *
 * DESCRIPTION :        Finds the energy numerically 
 * 
 */
double Hamiltonian::get_numerical_energy( double** r ){
// the step length and its squared inverse for the second derivative 
#define h 0.001
#define h2 1000000
  
  int i, j , k;
  double e_local, wfminus, wfplus, wfold, e_kinetic, e_potential, r_12, r_single_particle;
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

  // compute the potential energy 
  e_potential = 0;

  // contribution from electron-proton potential  
  for (i = 0; i < n_particles; i++) { 
    r_single_particle = 0;
    for (j = 0; j < dim; j++) { 
      r_single_particle += r[i][j]*r[i][j];
    }
    e_potential -= charge/sqrt(r_single_particle);
  }

  // contribution from electron-electron potential  
  for (i = 0; i < n_particles-1; i++) { 
    for (j = i+1; j < n_particles; j++) {
      r_12 = 0;  
      for (k = 0; k < dim; k++) { 
	r_12 += (r[i][k]-r[j][k])*(r[i][k]-r[j][k]);
      }
      e_potential += 1/sqrt(r_12);          
    }
  }

  free_matrix((void **) r_plus); // free memory
  free_matrix((void **) r_minus);
  e_local = e_potential+e_kinetic;
  return e_local;
}

Hamiltonian::~Hamiltonian() {
}

