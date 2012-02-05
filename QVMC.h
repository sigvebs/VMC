/* 
 * File:   QVMC.h
 * Author: sigve
 *
 * Created on 5. februar 2012, 10:34
 */

#ifndef QVMC_H
#define	QVMC_H

#include "Wavefunction.h"
#include "Helium.h"

class QVMC {
public:
    QVMC();
    QVMC( Helium* , int );
    QVMC(const QVMC& orig);
    virtual ~QVMC();
    
    // Functions
    void solve();
    double optimal_step_length( );
    double difference( double );
    void mc_sampling( int, double, int&, double& , double& );
protected:
    Helium* wf;
    int mc_cycles;
    long int idum;
    /*
  int numproc, my_rank;
  int mc_samples;
  int steps_variation;
  int dim;
  int electrons;
  int z;
  double *energy, *energy_sq, *acc;
  double step_length_max, step_length_min;
  double tolerance;
  double alph, bet;
  double alpha_0, beta_0;
  double delta_alpha, delta_beta;
  long idum;
  bool jastrow;
  int active_parameter;
*/
};

#endif	/* QVMC_H */

