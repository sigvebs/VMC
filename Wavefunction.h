/* 
 * File:   Wavefunction.h
 * Author: Sigve
 *
 * Created on February 4, 2012, 10:55 PM
 */

#ifndef WAVEFUNCTION_H
#define	WAVEFUNCTION_H

#include <armadillo>

#include "Jastrow.h"
#include "Hermite.h"
#include "Orbital.h"
#include "Slater.h"

class Wavefunction {
public:
    Wavefunction();
    Wavefunction(int, int, double, double, bool, Orbital*, Jastrow*);
    
    // Functions
    int getNParticles(){ return n_particles;};
    int getDim(){ return dim;};
    double getAlpha(){ return alpha;};
    double getBeta(){ return beta;};
    double get_energy( double** );
    void set_Jastrow( bool jastrow){ this->jastrow=jastrow;};
    double get_ratio();
    double evaluate( mat );
    mat q_force();
    void set_r_new(mat, int);
    void evaluate_new();
    double get_wf_old(){ return WF_old;};
    double get_wf_new(){ return WF_new;};
    void accept_move();
    double get_laplacian(){return energy;};
    void calculate_laplacian();
    void init_slater();
protected:
    mat r_old;
    mat r_new;
    Jastrow *jas;
    Slater *slater;
    Orbital *orbital;
    int dim;
    int n_particles;
    double alpha;
    double beta;
    bool jastrow;
    double WF_old;
    double WF_new;
    int active_particle;
    double energy;
};

#endif	/* WAVEFUNCTION_H */

