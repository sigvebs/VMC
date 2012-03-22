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
#include "../includes/ini.h"

// General imports
#include "../Wavefunction.h"
#include "../Potential.h"
#include "../Coulomb_pot.h"
#include "../Hamiltonian.h"
#include "../Interaction.h"
#include "../QD_electron_interaction.h"
#include "../Kinetic.h"
#include "../Kinetic_electron.h"
#include "../Orbital.h"
#include "../Jastrow.h"
#include "../MC_Brute_Force.h"
#include "../MC_Importance_Sampling.h"
#include "../QVMC.h"

// QD imports
#include "QD_VMC_APP.h"
#include "QD_wavefunction.h"
#include "QD_Harmonic_osc.h"
#include "QD_kinetic.h"
#include "QD_Orbital.h"
#include "QD_Jastrow.h"

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

    idum -= my_rank; // - time(NULL);
    mc_cycles /= numproc;

    // Initiating Energy classes
    Potential* potential = new QD_Harmonic_osc(dim, n_particles, w);
    Interaction* interaction = new QD_electron_interaction(dim, n_particles);
    Kinetic* kinetic = new QD_kinetic(dim, n_particles, w);
    Hamiltonian* ht = new Hamiltonian(potential, interaction, kinetic, jastrow);

    // Running over all variational parameters.
    for (int i = 0; i < a_steps; i++) {
        a = a_start + i*delta_a;
        paramset[i] = new QVMC*[b_steps];

        for (int j = 0; j < b_steps; j++) {
            b = b_start + j*delta_b;

            // Generating the total wave function.
            Jastrow* jastrow_function = new QD_Jastrow(dim, n_particles, b);
            Orbital* orbital = new QD_Orbital(dim, a, w);
            Wavefunction* wf = new QD_wavefunction(dim, n_particles, a, b, w, jastrow, orbital, jastrow_function);
            
            kinetic->set_wf(wf);

            if (sampling == 0)
                paramset[i][j] = new MC_Brute_Force(ht, wf, mc_cycles, idum);
            else if (sampling == 1) {
                paramset[i][j] = new MC_Importance_Sampling(ht, wf, mc_cycles, idum);
            }

            paramset[i][j]->solve();

            // MPI.
            tmp = paramset[i][j]->get_energy();
            MPI_Allreduce(&tmp, &tot_energy, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
            tot_energy /= numproc;

            tmp = paramset[i][j]->get_energy_sq();
            MPI_Allreduce(&tmp, &tot_energy_sq, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
            tot_energy_sq /= numproc;

            tmp = paramset[i][j]->get_accepted();
            MPI_Allreduce(&tmp, &accepted, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
            accepted /= numproc;

            // Printing progress.
            if (my_rank == 0) {
                cout << a << ", " << b << " Energy = " << tot_energy
                        << ", Variance = " << tot_energy_sq - tot_energy * tot_energy
                        << ", Sigma = " << sqrt(tot_energy_sq - tot_energy * tot_energy)
                        << ", Accepted = " << accepted / mc_cycles
                        << ", MC cycles = " << mc_cycles * numproc
                        << "\n";
            }
            paramset[i][j]->set_energy(tot_energy);
            paramset[i][j]->set_energy_sq(tot_energy_sq);
            paramset[i][j]->set_accepted(accepted);
        }
    }

    // Writing results to file.
    if (write_to_file) {
        if (my_rank == 0) {
            QD_write_to_file();
            cout << "Writing data to file..." << endl;
        }
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
void QD_VMC_APP::QD_write_to_file() {
    double a, b;
    double energy, energy_sq;

    ofstream outStream;
    outStream.open((const char*) &file_name[0]);

    // Running over all variational parameters
    for (int i = 0; i < a_steps; i++) {
        a = a_start + i*delta_a;
        
        for (int j = 0; j < b_steps; j++) {
            b = b_start + j*delta_b;
            energy = paramset[i][j]->get_energy();
            energy_sq = paramset[i][j]->get_energy_sq();
            outStream << a << " " << b << " " << energy << " " << energy_sq << "\n";
        }
    }
    outStream.close();
}

/*******************************************************************
 * 
 * NAME :               QD_VMC_APP( )
 *
 * DESCRIPTION :        Constructor. Reads data from an QD.ini
 *                      which contains all runtime variables.
 * 
 */
QD_VMC_APP::QD_VMC_APP() {
    // Reading data from QD.ini
    ini INIreader("QD.ini");

    mc_cycles = (int) INIreader.GetDouble("main", "mc_cycles");
    w = (int) INIreader.GetDouble("main", "w");
    dim = INIreader.GetInt("main", "dim");
    n_particles = INIreader.GetInt("main", "n_particles");

    a_start = INIreader.GetDouble("main", "a_start");
    b_start = INIreader.GetDouble("main", "b_start");
    a_steps = INIreader.GetDouble("main", "a_steps");
    b_steps = INIreader.GetDouble("main", "b_steps");

    delta_a = INIreader.GetDouble("main", "delta_a");
    delta_b = INIreader.GetDouble("main", "delta_b");

    sampling = INIreader.GetInt("main", "sampling");
    jastrow = INIreader.GetBool("main", "jastrow");
    blocking = INIreader.GetBool("main", "blocking");

    write_to_file = INIreader.GetBool("main", "write_to_file");
    file_name = INIreader.GetString("main", "file_name");

    paramset = new QVMC**[a_steps];

    QD_run_VMC();
}