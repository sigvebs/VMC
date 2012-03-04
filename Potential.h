/* 
 * File:   Potential.h
 * Author: Sigve
 *
 * Created on February 4, 2012, 10:56 PM
 */

#ifndef POTENTIAL_H
#define	POTENTIAL_H

#include <armadillo>
using namespace arma;

class Potential {
public:
    Potential();
    Potential( int, int );
    
    virtual double evaluate(mat) = 0;
    
protected:
    int n_particles;
    int dim;
};

#endif	/* POTENTIAL_H */

