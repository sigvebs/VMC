/* 
 * File:   main.cpp 
 * Author: Sigve

 *
 * Created on February 4, 2012, 10:41 PM
 */

#include <cstdlib>
#include "QVMC.h"
#include "Wavefunction.h"

// Includes
#include "Potential.h"
#include "Coulomb_pot.h"
#include "Hamiltonian.h"
#include "Interaction.h"
#include "electron_interaction.h"
#include "Kinetic.h"
#include "Kinetic_electron.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Defining values
    int mc_cycles = (int)1e6;
    
    // Defining atom and dimensions
    int dim, n_particles;
    double a, b, charge;    
    long idum = -1;
    a = 1.832;
    b = 0.4;
    n_particles = 2;
    dim = 3;
    charge = 2.0;
    
    // Initiating settings
    Potential* potential = new Coulomb_pot( dim, n_particles, charge );
    Interaction* interaction = new electron_interaction( dim, n_particles, charge );
    Kinetic* kinetic = new Kinetic_electron(dim, n_particles, charge );
    
    Hamiltonian* ht = new Hamiltonian( potential, interaction, kinetic );
    
    Wavefunction* wf = new Wavefunction( dim, n_particles, a, b, charge );
    kinetic->set_wf( wf );
    QVMC* test = new QVMC( ht, wf, mc_cycles, idum );
    test->solve();
    
    return 0;
}

