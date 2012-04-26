/* 
 * File:   One_Body_Density.h
 * Author: sigve
 *
 * Created on 3. april 2012, 14:22
 */

#ifndef ONE_BODY_DENSITY_H
#define	ONE_BODY_DENSITY_H

#include <armadillo>
#include <mpi.h>
#include "../Wavefunction.h"
using namespace arma;

class One_Body_Density {
public:
    One_Body_Density();
    void write_to_file(mat, double);
    double MC_integrator( vec, int );
    mat normalize(mat);
protected:
    int MC_samples;
    Wavefunction* wf;
    int dim;
    int N_particles;
    long idum; 
    int rank;
    int num_proc;
    MPI_Status status;

};

#endif	/* ONE_BODY_DENSITY_H */

