/* 
 * File:   Jastrow.cpp
 * Author: sigve
 * 
 * Created on 29. februar 2012, 17:12
 */

#include "Jastrow.h"

/*******************************************************************
 * 
 * NAME :               Jastrow( double** r )
 *
 * DESCRIPTION :        Constructor.
 * 
 */
Jastrow::Jastrow(int dim, int n_particles, double beta) {
    this->dim = dim;
    this->n_particles = n_particles;
    this->beta = beta;
}

/*******************************************************************
 * 
 * NAME :               get_ratio(vec r, int active_particle)
 *
 * DESCRIPTION :        Returns the R_J ratio used in the 
 *                      Metropolis test.
 * 
 */
double Jastrow::get_ratio(mat r_new, mat r_old ) {
    // This is an inefficent way of solving the problem since 
    // the are evaluating all new distances. Which particle 
    // we are evaluating should be implemented in the WF. 
    double delta_J = evaluate(r_new) - evaluate(r_old);
    return exp(delta_J);
}