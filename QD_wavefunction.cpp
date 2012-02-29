/* 
 * File:   qd_wavefunction.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 09:26
 */

#include "QD_wavefunction.h"
#include <math.h>
#include "lib.h"
#include "QD_Jastrow.h"

/*******************************************************************
 *
 * NAME :               QD_wavefunction( double** r)
 *
 * DESCRIPTION :        Constructor
 *
 */
QD_wavefunction::QD_wavefunction(int dim, int n_particles, double alpha, double beta, double w, bool jastrow) : w(w), Wavefunction(dim, n_particles, alpha, beta, jastrow) {

}

/*******************************************************************
 * 
 * NAME :               eval_simple( double** r)
 *
 * DESCRIPTION :        Evaluates the 'simple' wavefunction at the coordinate r.
 * 
 */
double QD_wavefunction::eval_simple(double** r) {
    double argument = 0;
    double r_;

    for (int i = 0; i < n_particles; i++) {
        r_ = 0;
        for (int j = 0; j < dim; j++) {
            r_ += r[i][j] * r[i][j];
        }
        argument += r_;
    }

    return exp(-0.5 * alpha * w * argument);
}

/*******************************************************************
 * 
 * NAME :               get_simple_gradient( double** r, int particle_number )
 *
 * DESCRIPTION :        Evaluates the simple Wavefunction's gradient in r
 * 
 */
double QD_wavefunction::get_simple_gradient(double** r, int active, int component) {
    return -w * alpha * r[active][component];
}