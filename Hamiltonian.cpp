/* 
 * File:   Hamiltonian.cpp
 * Author: zigg
 * 
 * Created on February 7, 2012, 7:36 PM
 */

#include "Coulomb_pot.h" 
#include "Hamiltonian.h"
#include <math.h>
#include "lib.h"
#include <iostream>

/*******************************************************************
 * 
 * NAME :               Hamiltonian( Wavefunction* wf )
 *
 * DESCRIPTION :        Constructor 
 * 
 */
Hamiltonian::Hamiltonian( Potential* potential, Interaction* interaction, Kinetic* kinetic ) {
    this->potential = potential;
    this->interaction = interaction;
    this->kinetic = kinetic;
}

/*******************************************************************
 * 
 * NAME :               get_energy( double** r)
 *
 * DESCRIPTION :        Return the local energy at the coordinate r.
 * 
 */
double Hamiltonian::get_energy( double** r){
    double energy;
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
/*
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
*/

/*******************************************************************
 * 
 * NAME :               get_numerical_energy( double** r )
 *
 * DESCRIPTION :        Finds the energy numerically 
 * 
 */
double Hamiltonian::get_numerical_energy( double** r ){
// the step length and its squared inverse for the second derivative 
    double e_pot, e_int, e_kin = 0;
    
    e_pot = potential->evaluate(r);
    e_int = interaction->evaluate(r);
    e_kin = kinetic->evaluate(r);
    
    return e_pot + e_int + e_kin;
}

Hamiltonian::~Hamiltonian() {
}

