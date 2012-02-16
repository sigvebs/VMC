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
Hamiltonian::Hamiltonian(Potential* potential, Interaction* interaction, Kinetic* kinetic) {
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
double Hamiltonian::get_energy(double** r) {
    double energy;
    energy = get_numerical_energy(r);

    return energy;
}

/*******************************************************************
 * 
 * NAME :               get_numerical_energy( double** r )
 *
 * DESCRIPTION :        Finds the energy numerically 
 * 
 */
double Hamiltonian::get_numerical_energy(double** r) {
    // the step length and its squared inverse for the second derivative 
    double e_pot, e_int, e_kin = 0;

    e_pot = potential->evaluate(r);
    e_int = interaction->evaluate(r);
    e_kin = kinetic->evaluate(r);

    return e_pot + e_int + e_kin;
}

Hamiltonian::~Hamiltonian() {
}

