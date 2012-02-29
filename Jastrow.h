/* 
 * File:   Jastrow.h
 * Author: sigve
 *
 * Created on 29. februar 2012, 17:12
 */

#ifndef JASTROW_H
#define	JASTROW_H

class Jastrow {
public:
    Jastrow(int, int, double);
    virtual double evaluate(double**) = 0;
    virtual double get_gradient(double**, int, int) = 0;
protected:
    int dim;
    int n_particles;
    double beta;
};

#endif	/* JASTROW_H */

