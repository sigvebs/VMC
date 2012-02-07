/* 
 * File:   Hamiltonian.h
 * Author: zigg
 *
 * Created on February 7, 2012, 7:36 PM
 */

#ifndef HAMILTONIAN_H
#define	HAMILTONIAN_H
#include "Wavefunction.h"
class Hamiltonian {
public:
    Hamiltonian();
    Hamiltonian( Wavefunction* );
    Hamiltonian(const Hamiltonian& orig);
    virtual ~Hamiltonian();
    double get_energy( double** r);
protected:
    Wavefunction* wf;
    int dim;
    int n_particles;
    double alpha;
    double beta;
    double charge;
};

#endif	/* HAMILTONIAN_H */

