/* 
 * File:   Blocking.cpp
 * Author: sigve
 * 
 * Created on 7. april 2012, 15:43
 */

#include <armadillo>
#include "../includes/lib.h"
#include "Blocking.h"
#include <fstream>
#include <string.h>

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*******************************************************************
 * 
 * NAME :               Blocking() 
 *
 * DESCRIPTION :        
 * 
 */
Blocking::Blocking() {
    int local_N;
    int N;
    int n_procs = 4;
    int delta_block_size = 10;
    int max_block_size = (int) 1e4;

    // Collecting file size information.
    struct stat result;
    if (stat("Blocking/files/blocking_0.dat", &result) == 0) {
        local_N = result.st_size / sizeof (double);
        N = local_N*n_procs;
    }
    double* MC_results = new double[local_N];

    // Collecting data
    vec MC_data = zeros(N, 1);
    for (int i = 0; i < n_procs; i++) {
        ostringstream ost;
        ost << "Blocking/files/blocking_" << i << ".dat";
        ifstream infile;
        infile.open(ost.str().c_str(), ios::in | ios::binary);
        infile.read((char*) MC_results, result.st_size);
        infile.close();
        for (int j = 0; j < local_N; j++)
            MC_data(j+i*local_N) += MC_results[j];
    }
    MC_data /= n_procs;
    delete MC_results;

    // Looping over block sizes and storing results.
    int block_size;
    vec results;
    double mean, sigma;


    ofstream outStream;
    outStream.open("Blocking/files/blocking_results.dat");

    for (int i = 1; i < max_block_size / delta_block_size; i++) {
        block_size = i*delta_block_size;
        results = block(MC_data, block_size, N);
        mean = results(0);
        sigma = results(1);
        outStream << block_size << "\t" << mean << "\t" << sigma << "\n";
    }
    outStream.close();
}

/*******************************************************************
 * 
 * NAME :               block(vec MC_data, int block_size) 
 *
 * DESCRIPTION :        Calculates the mean and variance of
 *                      the blocks of MC-data.
 * 
 */
vec Blocking::block(vec MC_data, int block_size, int N_samples) {

    int N_blocks = N_samples / block_size;
    vec results = zeros(2, 1);

    vec E_block = zeros(N_blocks, 1);

    // Finding the mean values of the blocks
    double delta_E;
    for (int i = 0; i < N_blocks; i++) {
        // Finding the average over one block
        delta_E = 0;
        for (int j = i * block_size; j < i * block_size + block_size; j++)
            delta_E += MC_data(j);

        E_block(i) = delta_E / block_size;
    }

    // Calulating the mean and variance of all the blocks
    double E = 0;
    double E_2 = 0;
    for (int i = 0; i < N_blocks; i++) {
        E += E_block(i);
        E_2 += E_block(i) * E_block(i);
    }
    E /= N_blocks;
    E_2 /= N_blocks;
    double sigma = E_2 - E*E;

    sigma = sqrt(sigma / N_blocks);
    results(0) = E;
    results(1) = sigma;

    return results;
}
