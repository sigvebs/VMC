/* 
 * File:   QVMC.cpp
 * Author: sigve
 * 
 * Created on 5. februar 2012, 10:34
 */

#include "QVMC.h"
#include "lib.h"
#include <iostream>

void QVMC::mc_sampling( int cycles, double step_length, int& accepted, double& loc_energy, double& loc_energy_sq){    
    double dim, n_particles;
    double wf_old, wf_new, delta_e;
    int i, j;
    double **r_old, **r_new;

    dim         = wf->getDim();
    n_particles = wf->getNParticles();

    // Inititating variables
    loc_energy = loc_energy_sq = delta_e = 0;
    accepted = 0;
    
    r_old = (double **) matrix( n_particles, dim, sizeof(double) );
    r_new = (double **) matrix( n_particles, dim, sizeof(double) );
    
    // Initial random position of the particles
    for( i=0; i<n_particles; i++){
        for( j=0; j<dim; j++) {
            r_new[i][j] = 0;
            r_old[i][j] = step_length*( ran2( &idum ) - 0.5 );

        }
    }
    wf_old = wf->evaluate( r_old );

    // Looping over all MC-cycles
    for( int n=0; n<cycles; n++ ){
        // Changes the position of the electrons
        for( i=0; i<n_particles; i++){
            for( j=0; j<dim; j++){
                r_new[i][j] = r_old[i][j] + step_length*( ran2( &idum ) - 0.5 );
            }
        }
        wf_new = wf->evaluate( r_new );
        // Metropolis test 
        if( ran2( &idum ) <= wf_new*wf_new / wf_old/wf_old ) {
            for( i=0; i<n_particles; i++){
                for( j=0; j<dim; j++)
                r_old[i][j] = r_new[i][j];
            }
            wf_old = wf_new;
            accepted++;
        }          
        // Computing local energy
        delta_e        = wf->get_energy( r_old );
        loc_energy    += delta_e;
        loc_energy_sq += delta_e*delta_e;
    }
    free_matrix( (void**) r_old );
    free_matrix( (void**) r_new );
    
    loc_energy /= cycles;
    loc_energy_sq /= cycles;
}

void QVMC::solve( ){
    double step_length, energy, energy_sq;
    int accepted;
    
    step_length = optimal_step_length();
    mc_sampling( mc_cycles, step_length, accepted, energy, energy_sq );

    cout << "Step length = " << step_length << "\n";
    cout << "<E> = " << energy << "\n";
    cout << "<E^2> = " << energy_sq << "\n";
}

QVMC::QVMC() {    
}

QVMC::QVMC( Helium* wf_, int cycles ) {
    wf = wf_;
    mc_cycles = cycles;
    idum = -1;
}

QVMC::QVMC(const QVMC& orig) {
}

QVMC::~QVMC() {
}

double QVMC::optimal_step_length(){
  double min, max, tolerance;
  min = 0.01;
  max = 3;
  tolerance = 0.01;
 
  while( (max - min) > tolerance ){
    if( difference( min )*difference( (min + max)/2 ) < 0 )
	max = (min + max) / 2;
    else
	min = (min + max) / 2;
  }
  return (min + max) / 2;
}

double QVMC::difference( double step_length ){
    double tmp1, tmp2;
    double tot_energy, tot_energy_sq; 
    int accepted, mc_samples_sl;
    mc_samples_sl =  (int)1e5;
    tot_energy = tot_energy_sq = 0; 
    accepted = 0;
    mc_sampling( mc_samples_sl, step_length, accepted, tmp1, tmp2 );
    return (double) accepted/(mc_samples_sl) - 0.5;
}
