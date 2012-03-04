/* 
 * File:   qd_wavefunction.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 09:26
 */

#include "QD_wavefunction.h"
#include <math.h>
#include "../includes/lib.h"
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
