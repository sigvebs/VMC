/* 
 * File:   Jastrow.h
 * Author: sigve
 *
 * Created on 29. februar 2012, 17:12
 */

#ifndef JASTROW_H
#define	JASTROW_H

#include <armadillo>
using namespace arma;

class Jastrow {
public:
    Jastrow(int, int, double);
    rowvec get_gradient(){ return gradient; };
    virtual double evaluate(mat) = 0;
    virtual void compute_gradient(mat, int) = 0;
    virtual double get_laplacian(mat, int) = 0;
protected:
    int dim;
    int n_particles;
    double beta;
    rowvec gradient;
};

#endif	/* JASTROW_H */

