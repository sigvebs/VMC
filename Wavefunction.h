/* 
 * File:   Wavefunction.h
 * Author: Sigve
 *
 * Created on February 4, 2012, 10:55 PM
 */

#ifndef WAVEFUNCTION_H
#define	WAVEFUNCTION_H

#include "Jastrow.h"
#include "Hermite.h"
#include "Slater.h"
#include <armadillo>

class Wavefunction {
public:
    Wavefunction();
    Wavefunction(int, int, double, double, bool);
    
    // Functions
    int getNParticles(){ return n_particles;};
    int getDim(){ return dim;};
    double getAlpha(){ return alpha;};
    double getBeta(){ return beta;};
    double get_energy( double** );
    void set_Jastrow( bool jastrow){ this->jastrow=jastrow;};
    
    double evaluate( mat );
    mat q_force( mat );
    void set_r_new(mat r_new);
    void evaluate_new();
    double get_wf_old(){ return WF_old;};
    double get_wf_new(){ return WF_new;};
    void accept_move();
    double get_laplacian(mat);
protected:
    mat r_old;
    mat r_new;
    Jastrow *jas;
    Slater *slater;
    int dim;
    int n_particles;
    double alpha;
    double beta;
    bool jastrow;
    double WF_old;
    double WF_new;
};

#endif	/* WAVEFUNCTION_H */

