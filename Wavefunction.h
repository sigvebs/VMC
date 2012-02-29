/* 
 * File:   Wavefunction.h
 * Author: Sigve
 *
 * Created on February 4, 2012, 10:55 PM
 */

#ifndef WAVEFUNCTION_H
#define	WAVEFUNCTION_H

#include "Jastrow.h"

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
    
    double evaluate( double** );
    void q_force( double**, double** );
    virtual double eval_simple( double** ) = 0;
    virtual double get_simple_gradient( double**, int, int ) = 0;
protected:
    Jastrow *jas;
    int dim;
    int n_particles;
    double alpha;
    double beta;
    bool jastrow;
};

#endif	/* WAVEFUNCTION_H */

