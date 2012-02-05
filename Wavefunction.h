/* 
 * File:   Wavefunction.h
 * Author: Sigve
 *
 * Created on February 4, 2012, 10:55 PM
 */

#ifndef WAVEFUNCTION_H
#define	WAVEFUNCTION_H

class Wavefunction {
public:
    Wavefunction();
    Wavefunction(int, int, double, double);
    Wavefunction(const Wavefunction& orig);
    virtual ~Wavefunction();
    
    // Functions
    int getDim(){ return dim;};
    int getNParticles(){ return n_particles;};
    //double evaluate( double** ){ return 1;};
protected:
    int dim;
    int n_particles;
    double alpha;
    double beta;
};

#endif	/* WAVEFUNCTION_H */

