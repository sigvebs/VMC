/* 
 * File:   QD_electron_interaction.cpp
 * Author: sigve
 * 
 * Created on 3. mars 2012, 17:08
 */

#include "QD_electron_interaction.h"

QD_electron_interaction::QD_electron_interaction(int dim, int n_particles) : Interaction(dim, n_particles) {
}


/*******************************************************************
 * 
 * NAME :               evaluate(mat r)
 *
 * DESCRIPTION :        In progress.
 * 
 */
double QD_electron_interaction::evaluate(mat r) {
    double r_ij;
    double e_potential = 0;

    // Contribution from electron-electron potential  
    for (int i = 0; i < n_particles; i++) {
        for (int j = i + 1; j < n_particles; j++) {
            r_ij = norm(r.row(i) - r.row(j),2);
            e_potential += 1.0 / r_ij;        
        }
    }
    return e_potential;
}

