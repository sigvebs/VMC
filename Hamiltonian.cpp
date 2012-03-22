/* 
 * File:   Hamiltonian.cpp
 * Author: zigg
 * 
 * Created on February 7, 2012, 7:36 PM
 */

#include "Hamiltonian.h"
#include <math.h>
#include <iostream>
#include "includes/lib.h"

/*******************************************************************
 * 
 * NAME :               Hamiltonian( Wavefunction* wf )
 *
 * DESCRIPTION :        Constructor 
 * 
 */
Hamiltonian::Hamiltonian(Potential* potential, Interaction* interaction, Kinetic* kinetic, bool jastrow) {
    this->jastrow = jastrow;
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
double Hamiltonian::get_energy(mat r) {
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
double Hamiltonian::get_numerical_energy(mat r) {
    double e_pot, e_int, e_kin;

    e_pot = potential->evaluate(r);
    if (jastrow)
        e_int = interaction->evaluate(r);
    else
        e_int = 0;
    
    e_kin = kinetic->evaluate(r);
#if 0 // DEBUG
    cout << "Potential = " << e_pot << endl;
    cout << "Interaction = " << e_int << endl;
    cout << "Kinteic = " << e_kin << endl;
#endif
    
    return e_pot + e_int + e_kin;
}