/* 
 * File:   main.cpp 
 * Author: Sigve

 *
 * Created on February 4, 2012, 10:41 PM
 */
#include <math.h>
#include <cstdlib>


// Includes
#include "QVMC.h"
#include "Wavefunction.h"
#include "Potential.h"
#include "Coulomb_pot.h"
#include "Hamiltonian.h"
#include "Interaction.h"
#include "electron_interaction.h"
#include "Kinetic.h"
#include "Kinetic_electron.h"

// Includes QD
#include "QD_wavefunction.h"
#include "Harmonic_osc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Defining values
    int mc_cycles = (int)1e8;
    
    // Defining atom and dimensions
    int dim, n_particles;
    double a, b, charge;    
    long idum = -1;
    a = 1.832;
    b = 0.4;
    n_particles = 2;
    dim = 2;
    charge = 2.0;
    
    // Quantum Dots
    n_particles = 2;
    dim = 2;
    double w = 1;
    a = 0.987;
    b = 0.398;
    
    // Initiating settings
    //Potential* potential = new Coulomb_pot( dim, n_particles, charge );
    Potential* potential = new Harmonic_osc( dim, n_particles, w );
    Interaction* interaction = new electron_interaction( dim, n_particles );
    Kinetic* kinetic = new Kinetic_electron(dim, n_particles );
    
    Hamiltonian* ht = new Hamiltonian( potential, interaction, kinetic );
    
    //Wavefunction* wf = new Wavefunction( dim, n_particles, a, b, charge );
    Wavefunction* wf = new QD_wavefunction( dim, n_particles, a, b, w );
    wf->set_Jastrow(true);
    kinetic->set_wf( wf );
    QVMC* test = new QVMC( ht, wf, mc_cycles, idum );
    test->solve();
    
    return 0;
}

