/* 
 * File:   Coulomb_pot.cpp
 * Author: sigve
 * 
 * Created on 8. februar 2012, 17:18
 */

#include "Coulomb_pot.h"
#include <math.h>

/*******************************************************************
 * 
 * NAME :               evaluate( double** r)
 *
 * DESCRIPTION :        Evaluates the Coulomb potential at the coordinate r.
 * 
 */
double Coulomb_pot:: evaluate( double** r ) {
    double r_single_particle, r_12;
    double e_potential = 0;

    // contribution from electron-proton potential  
    for (int i = 0; i < n_particles; i++) {
        r_single_particle = 0;
        for (int j = 0; j < dim; j++) {
            r_single_particle += r[i][j] * r[i][j];
        }
        e_potential -= charge / sqrt(r_single_particle);
    }


    return e_potential;
}

/*******************************************************************
 * 
 * NAME :               Coulomb_pot( int dim, int n_particles, double charge):Potential( dim, n_particles, charge)
 *
 * DESCRIPTION :        Constructor.
 * 
 */
Coulomb_pot::Coulomb_pot( int dim, int n_particles, double charge):Potential( dim, n_particles, charge){
    
    
}

Coulomb_pot::~Coulomb_pot() {
}

