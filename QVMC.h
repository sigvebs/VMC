/* 
 * File:   QVMC.h
 * Author: sigve
 *
 * Created on 5. februar 2012, 10:34
 */

#ifndef QVMC_H
#define	QVMC_H

#include "Wavefunction.h"
#include "Hamiltonian.h"

class QVMC {
public:
    QVMC();
    QVMC( Hamiltonian*, Wavefunction*, int, long );
    QVMC(const QVMC& orig);
    virtual ~QVMC();
    
    // Functions
    void solve();
    double optimal_step_length( );
    double difference( double );
    void mc_sampling( int, double, int&, double& , double& );
    double get_energy(){ return energy;};
    double get_energy_sq(){ return energy_sq;};
    double get_accepted(){ return accepted;};
    double get_step_length(){ return step_length;};
protected:
    Wavefunction* wf;
    Hamiltonian* ht;
    int mc_cycles;
    long idum;
    int thermalization;
    
    double energy;
    double energy_sq;
    double accepted;
    double step_length;
};

#endif	/* QVMC_H */

