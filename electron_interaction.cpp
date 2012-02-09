/* 
 * File:   electron_interaction.cpp
 * Author: sigve
 * 
 * Created on 8. februar 2012, 18:32
 */

#include "electron_interaction.h"
#include <math.h>

electron_interaction::electron_interaction(int dim, int n_particles ): Interaction(dim, n_particles ){
}

/*******************************************************************
 * 
 * NAME :               evaluate( double* r)
 *
 * DESCRIPTION :        In progress.
 * 
 */
double electron_interaction::evaluate( double** r){
    double r_12;
    double e_potential = 0;
    // Contribution from electron-electron potential  
    for (int i = 0; i < n_particles - 1; i++) {
        for (int j = i + 1; j < n_particles; j++) {
            r_12 = 0;
            for (int k = 0; k < dim; k++) {
                r_12 += (r[i][k] - r[j][k])*(r[i][k] - r[j][k]);
            }
            e_potential += 1 / sqrt(r_12);
        }
    }
    return e_potential;
}

electron_interaction::~electron_interaction() {
}

