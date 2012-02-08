/* 
 * File:   Hamiltonian.h
 * Author: zigg
 *
 * Created on February 7, 2012, 7:36 PM
 */

#ifndef HAMILTONIAN_H
#define	HAMILTONIAN_H
#include "Wavefunction.h"
#include "Kinetic.h"
#include "Potential.h"
#include "Interaction.h"
#include "Kinetic.h"

class Hamiltonian {
public:
    Hamiltonian();
    //Hamiltonian( Wavefunction* );
    Hamiltonian( Potential*, Interaction*, Kinetic* );
    virtual ~Hamiltonian();
    double get_energy( double** r);
protected:
    // Protected variables
    Wavefunction* wf;
    int dim;
    int n_particles;
    double alpha;
    double beta;
    double charge;
    bool analytic_energy;
    
    // New variabels
    Potential* potential;
    Interaction* interaction;
    Kinetic* kinetic;
    
    // Protected functions
    double get_analytic_energy( double** );
    double get_numerical_energy( double** r );
};

#endif	/* HAMILTONIAN_H */

