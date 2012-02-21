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
    QVMC(Hamiltonian*, Wavefunction*, int, long);
    QVMC(const QVMC& orig);
    virtual ~QVMC();

    // Functions
    virtual void solve() = 0;

    double get_energy() {
        return energy;
    };

    double get_energy_sq() {
        return energy_sq;
    };

    double get_accepted() {
        return accepted;
    };

    void set_energy(double energy) {
        this->energy = energy;
    };

    void set_accepted(double accepted) {
        this->accepted = accepted;
    };

    void set_energy_sq(double energy_sq) {
        this->energy_sq = energy_sq;
    };
protected:
    Wavefunction* wf;
    Hamiltonian* ht;
    int mc_cycles;
    long idum;
    int thermalization;

    double energy;
    double energy_sq;
    double accepted;
};

#endif	/* QVMC_H */

