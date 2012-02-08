/* 
 * File:   Potential.h
 * Author: Sigve
 *
 * Created on February 4, 2012, 10:56 PM
 */

#ifndef POTENTIAL_H
#define	POTENTIAL_H

class Potential {
public:
    Potential();
    Potential( int, int, double );
    Potential(const Potential& orig);
    double solve(double**);
    virtual ~Potential();
protected:
    int n_particles;
    int dim;
    int charge;
};

#endif	/* POTENTIAL_H */

