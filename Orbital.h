/* 
 * File:   Orbital.h
 * Author: sigve
 *
 * Created on 1. mars 2012, 09:27
 */

#ifndef ORBITAL_H
#define	ORBITAL_H

#include "Hermite.h"
#include <armadillo>
using namespace arma;

class Orbital {
public:
    Orbital(int, double);
    virtual double evaluate(rowvec, int, int) = 0;
    virtual rowvec get_gradient(rowvec, int, int) = 0;
    virtual double evaluate_laplacian(rowvec, int, int) = 0;
    virtual double evaluate_exp(rowvec) = 0;
protected:
    int dim;
    Hermite *H;
    double alpha;
};

#endif	/* ORBITAL_H */

