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
    Potential( int, int );
    Potential(const Potential& orig);
    
    virtual double evaluate(double**) = 0;
    
    virtual ~Potential();
protected:
    int n_particles;
    int dim;
};

#endif	/* POTENTIAL_H */

