/* 
 * File:   qd_wavefunction.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 09:26
 */

#include "QD_wavefunction.h"

/*******************************************************************
 *
 * NAME :               QD_wavefunction( double** r)
 *
 * DESCRIPTION :        Constructor
 *
 */
QD_wavefunction::QD_wavefunction(int dim, int n_particles, double alpha, double beta, double w, bool jastrow, Orbital* orbital, Jastrow* jas)
:  w(w), Wavefunction(dim, n_particles, alpha, beta, jastrow, orbital, jas) {

}
