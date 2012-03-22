/* 
 * File:   Hamiltonian.h
 * Author: zigg
 *
 * Created on February 7, 2012, 7:36 PM
 */

#ifndef HAMILTONIAN_H
#define	HAMILTONIAN_H
#include <armadillo>
#include "Wavefunction.h"
#include "Kinetic.h"
#include "Potential.h"
#include "Interaction.h"

class Hamiltonian {
public:
    Hamiltonian();
    Hamiltonian(Potential*, Interaction*, Kinetic*, bool);
    double get_energy(mat);
protected:
    // Protected variables
    Wavefunction* wf;
    int dim;
    int n_particles;
    double alpha;
    double beta;
    double charge;
    bool analytic_energy;
    bool jastrow;

    Potential* potential;
    Interaction* interaction;
    Kinetic* kinetic;

    // Protected functions
    double get_analytic_energy(mat);
    double get_numerical_energy(mat);
};

#endif	/* HAMILTONIAN_H */

