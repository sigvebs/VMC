/* 
 * File:   main.cpp 
 * Author: Sigve

 *
 * Created on February 4, 2012, 10:41 PM
 */

#include <cstdlib>
#include "QVMC.h"
#include "Wavefunction.h"
#include "Helium.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Defining values
    int mc_cycles = (int)1e8;

    // Defining atom and dimensions
    int dim;
    int n_particles;
    double a, b;    

    a = 1.7;
    b = 1.6;
    n_particles = 2;
    dim = 3;
    
    Helium* wf = new Helium( dim, n_particles, a, b);
    QVMC* test = new QVMC( wf, mc_cycles );
    test->solve();
    return 0;
}

