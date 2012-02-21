/* 
 * File:   QD_VMC_APP.cpp
 * Author: sigve
 * 
 * Created on 13. februar 2012, 10:01
 */

using namespace std;
// Library includes
#include <iostream>
#include <fstream>
#include <string.h>
#include <mpi.h>
#include <math.h>
#include <sys/time.h>

// General imports
#include "Wavefunction.h"
#include "Potential.h"
#include "Coulomb_pot.h"
#include "Hamiltonian.h"
#include "Interaction.h"
#include "electron_interaction.h"
#include "Kinetic.h"
#include "Kinetic_electron.h"

// QD imports
#include "QD_VMC_APP.h"
#include "QVMC.h"
#include "QD_wavefunction.h"
#include "QD_Harmonic_osc.h"
#include "QD_kinetic.h"
#include "QD_MC_Brute_Force.h"
#include "QD_MC_Importance_Sampling.h"

/*******************************************************************
 * 
 * NAME :               QD_VMC_APP( )
 *
 * DESCRIPTION :        Constructor
 * 
 */
QD_VMC_APP::QD_VMC_APP() {
    // Initiating variables - later this should be imported from QD_param.ini
    mc_cycles = (int) 1e6;
    n_particles = 2;
    dim = 2;
    w = 1.0;

#if 1
    a_start = 0.987;
    b_start = 0.398;
#else
    a_start = 1.8;
    b_start = 0.4;
#endif

    a_steps = 1;
    delta_a = 0.02;

    b_steps = 1;
    delta_b = 0.02;

    // 0 = Brute Force, 1 = Importance Sampling
    sampling = 1;

    jastrow = true;

    paramset = new QVMC**[a_steps];
    write_to_file = false;
    QD_run_VMC();
}

QD_VMC_APP::~QD_VMC_APP() {
}

/*******************************************************************
 * 
 * NAME :               QD_run_VMC( )
 *
 * DESCRIPTION :        In progress
 * 
 */
void QD_VMC_APP::QD_run_VMC() {
    double a, b;
    double tot_energy, tot_energy_sq, accepted, tmp;
    long idum = -1;

    // MPI init
    int numproc, my_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    idum -= my_rank - time(NULL);
    mc_cycles /= numproc;

    // Initiating Energy classes
    Potential* potential = new QD_Harmonic_osc(dim, n_particles, w);
    Interaction* interaction = new electron_interaction(dim, n_particles);
    Kinetic* kinetic = new QD_kinetic(dim, n_particles, w);
    Hamiltonian* ht = new Hamiltonian(potential, interaction, kinetic);
    
    // Running over all variational parameters
    for (int i = 0; i < a_steps; i++) {
        a = a_start + i*delta_a;
        paramset[i] = new QVMC*[b_steps];
        for (int j = 0; j < b_steps; j++) {
            b = b_start + j*delta_b;

            Wavefunction* wf = new QD_wavefunction(dim, n_particles, a, b, w, jastrow);
            kinetic->set_wf(wf);

            if (sampling == 0)
                paramset[i][j] = new QD_MC_Brute_Force(ht, wf, mc_cycles, idum);
            else if (sampling == 1)
                paramset[i][j] = new QD_MC_Importance_Sampling(ht, wf, mc_cycles, idum);

            paramset[i][j]->solve();

            // MPI
            tmp = paramset[i][j]->get_energy();
            MPI_Allreduce(&tmp, &tot_energy, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
            tot_energy /= numproc;
            tmp = paramset[i][j]->get_energy_sq();
            MPI_Allreduce(&tmp, &tot_energy_sq, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
            tot_energy_sq /= numproc;
            tmp = paramset[i][j]->get_accepted();
            MPI_Allreduce(&tmp, &accepted, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
            accepted /= numproc;

            // Printing progress
            if (my_rank == 0) {
                cout << a << ", " << b << " Energy " << tot_energy
                        << " Variance " << tot_energy_sq - tot_energy * tot_energy
                        << " Sigma " << sqrt(tot_energy_sq - tot_energy * tot_energy)
                        << " Accepted " << accepted / mc_cycles
                        << "\n";
            }
            paramset[i][j]->set_energy(tot_energy);
            paramset[i][j]->set_energy_sq(tot_energy_sq);
            paramset[i][j]->set_accepted(accepted);
        }
    }

    // Writing results to file
    if (write_to_file) {
        if (my_rank == 0)
            QD_write_to_file("VMC_prf.dat");
    }

    MPI_Finalize();
}

/*******************************************************************
 * 
 * NAME :               QD_write_to_file( char* name )
 *
 * DESCRIPTION :        In progress
 * 
 */
void QD_VMC_APP::QD_write_to_file(char* name) {
    double a, b;
    double energy, energy_sq;

    ofstream outStream;
    outStream.open(name);

    // Running over all variational parameters
    for (int i = 0; i < a_steps; i++) {
        a = a_start + i*delta_a;
        //paramset[i] = new QVMC*[b_steps];
        for (int j = 0; j < b_steps; j++) {
            b = b_start + j*delta_b;
            energy = paramset[i][j]->get_energy();
            energy_sq = paramset[i][j]->get_energy_sq();
            outStream << a << " " << b << " " << energy << " " << energy_sq << "\n";
        }
    }
    outStream.close();
}