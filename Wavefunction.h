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
    virtual ~Wavefunction();
    
    // Functions
    int getNParticles(){ return n_particles;};
    int getDim(){ return dim;};
    double getAlpha(){ return alpha;};
    double getBeta(){ return beta;};
    double get_energy( double** );
    void set_Jastrow( bool jastrow){ this->jastrow=jastrow;};
    
    virtual double evaluate( double** ) = 0;
    virtual double eval_simple( double** ) = 0;
    virtual double eval_jastrow( double** ) = 0;
protected:
    int dim;
    int n_particles;
    double alpha;
    double beta;
    bool jastrow;
};

#endif	/* WAVEFUNCTION_H */

