/* 
 * File:   LA_VMC_APP.cpp
 * Author: sigve
 * 
 * Created on 13. februar 2012, 10:10
 */

#include "LA_VMC_APP.h"

// General imports
#include "QD_VMC_APP.h"
#include "QVMC.h"
#include "Wavefunction.h"
#include "Potential.h"
#include "Coulomb_pot.h"
#include "Hamiltonian.h"
#include "Interaction.h"
#include "electron_interaction.h"
#include "Kinetic.h"
#include "Kinetic_electron.h"

// QD imports
#include "Coulomb_pot.h"
#include "Kinetic_electron.h"

LA_VMC_APP::LA_VMC_APP() {    
    a = 1.832;
    b = 0.4;
    n_particles = 2;
    dim = 2;
    charge = 2.0;
}

LA_VMC_APP::~LA_VMC_APP() {
}

 void LA_VMC_APP::LA_run_VMC(){
    long idum = -1;
    
    Potential* potential = new Coulomb_pot( dim, n_particles, charge );
    Kinetic* kinetic = new Kinetic_electron(dim, n_particles );
    Interaction* interaction    = new electron_interaction( dim, n_particles );
    
    Hamiltonian* ht = new Hamiltonian( potential, interaction, kinetic );
    
    // Not working
    /*
    Wavefunction* wf = new Wavefunction( dim, n_particles, a, b, charge );
    wf->set_Jastrow(true);
    kinetic->set_wf( wf );
    
   //test->solve();
     * */
}
