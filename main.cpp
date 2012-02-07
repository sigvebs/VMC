/* 
 * File:   main.cpp 
 * Author: Sigve

 *
 * Created on February 4, 2012, 10:41 PM
 */

#include <cstdlib>
#include "QVMC.h"
#include "Wavefunction.h"

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
    a = 1.8;
    b = 0.4;
    n_particles = 2;
    dim = 3;
    charge = 2.0;
    
    Wavefunction* wf = new Wavefunction( dim, n_particles, a, b, charge);
    QVMC* test = new QVMC( wf, mc_cycles, idum );
    test->solve();
    return 0;
}

