/* 
 * File:   QVMC.cpp
 * Author: sigve
 * 
 * Created on 5. februar 2012, 10:34
 */

#include "QVMC.h"
#include "lib.h"

/*******************************************************************
 * 
 * NAME :               QVMC( Wavefunction* wf, int mc_cycles, long idum ) 
 *
 * DESCRIPTION :        Constructor
 */
QVMC::QVMC(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum) {
    this->ht = ht;
    this->wf = wf;
    this->mc_cycles = mc_cycles;
    this->idum = idum;
    thermalization = (int) 1e3;
}

QVMC::~QVMC() {
}
