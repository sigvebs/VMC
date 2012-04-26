/* 
 * File:   One_Body_Density.cpp
 * Author: sigve
 * 
 * Created on 3. april 2012, 14:22
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <mpi.h>
#include <time.h>

#include "One_Body_Density.h"
#include "../includes/lib.h"
#include "../QD/QD_wavefunction.h"
#include "../QD/QD_Orbital.h"
#include "../QD/QD_Jastrow.h"

/*******************************************************************
 * 
 * NAME :               One_Body_Density()
 *
 * DESCRIPTION :        Computes the one body density.
 * 
 */
One_Body_Density::One_Body_Density() {
    MC_samples = (int) 1e6;
    dim = 2;
    N_particles = 12;

    // 2 particles.
    double alpha = 0.987;
    double beta = 0.398;

    // 6 particles.
    alpha = 0.92;
    beta = 0.565;

    // 12 particles
    alpha = 0.87;
    beta = 0.68;

    double omega = 1.0;
    bool jastrow = true;

    // MPI init
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    idum = idum - rank - time(NULL);
    MC_samples /= num_proc;

    // Generating the total wave function.
    Jastrow* jastrow_function = new QD_Jastrow(dim, N_particles, beta);
    Orbital* orbital = new QD_Orbital(dim, alpha, omega);
    wf = new QD_wavefunction(dim, N_particles, alpha, beta, omega, jastrow, orbital, jastrow_function);

    // One body density
    int N = 50;
    mat rho = zeros(N, N);
    vec r = zeros<vec > (dim);
    double dr = 0.18;

    int count = 1;
    for (int i = 0; i < N; i++) {
        r(0) = (i - N / 2) * dr;
        for (int j = 0; j < N; j++) {
            r(1) = (j - N / 2) * dr;
            rho(i, j) = MC_integrator(r, count);
            count++;
        }
        cout << i << endl;
    }

    if (rank == 0) {
        rho = normalize(rho);
        write_to_file(rho, dr);
    }

    MPI_Finalize();
}

/*******************************************************************
 * 
 * NAME :               normalize(mat rho)
 *
 * DESCRIPTION :        A function that normalizes a 2D set of data.
 * 
 */
mat One_Body_Density::normalize(mat rho) {
    double norm = sum(sum(rho));

    return rho / norm;
}

/*******************************************************************
 * 
 * NAME :               MC_integrator(vec r_active) 
 *
 * DESCRIPTION :        Integrator using brute force MC integration.
 * 
 */
double One_Body_Density::MC_integrator(vec r_active, int id) {
    double sl = 6;
    double rho = 0;
    double wave_func;
    double y;
    double r_tmp;
    mat r = zeros(N_particles, dim);
    r.row(0) = r_active.t();

    // Init of the particle that is at a constant r
    for (int i = 0; i < MC_samples; i++) {
        // Generating new coordintes.
        for (int k = 1; k < N_particles; k++)
            for (int j = 0; j < dim; j++) {
                r(k, j) = sl * (ran2(&idum) - 0.5);
            }

        wave_func = wf->evaluate(r);
        rho += wave_func*wave_func;
    }

    double tmp = rho;

    if (rank != 0)
        MPI_Send(&rho, 1, MPI_DOUBLE, 0, id, MPI_COMM_WORLD);
        // Collecting data from the other processes.
    else {
        for (int i = 1; i < num_proc; i++) {
            MPI_Recv(&tmp, 1, MPI_DOUBLE, i, id, MPI_COMM_WORLD, &status);
            rho += tmp;
        }
    }
    rho /= num_proc;
    return rho;
}

/*******************************************************************
 * 
 * NAME :               QD_write_to_file( char* name )
 *
 * DESCRIPTION :        Writes the one body density to file.
 * 
 */
void One_Body_Density::write_to_file(mat rho, double dr) {
    string file_name = "One_Body_Density/files/rho.dat";
    double N = rho.n_rows;

    ofstream outStream;
    outStream.open((const char*) &file_name[0]);
    outStream << N << " " << dr << " " << MC_samples << endl;

    // Writing coordinates and density to file
    vec r = zeros(dim, 1);
    for (int i = 0; i < N; i++) {
        r(0) = (i - N / 2) * dr;
        for (int j = 0; j < N; j++) {
            r(1) = (j - N / 2) * dr;
            outStream << r(0) << " " << r(1) << " " << rho(i, j) << endl;
        }
    }
    outStream.close();
}