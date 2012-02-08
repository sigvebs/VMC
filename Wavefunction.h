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
    Wavefunction(int, int, double, double, double);
    virtual ~Wavefunction();
    
    // Functions
    int getNParticles(){ return n_particles;};
    int getDim(){ return dim;};
    double getAlpha(){ return alpha;};
    double getBeta(){ return beta;};
    double getCharge( ){ return charge; };
    double evaluate( double** );
    double get_energy( double** );
    double eval_simple( double** );
    double eval_jastrow( double** );
protected:
    int dim;
    int n_particles;
    double alpha;
    double beta;
    double charge;
    bool jastrow;
};

#endif	/* WAVEFUNCTION_H */

