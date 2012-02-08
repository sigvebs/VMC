/* 
 * File:   Coulomb_pot.h
 * Author: sigve
 *
 * Created on 8. februar 2012, 17:18
 */

#ifndef COULOMB_POT_H
#define	COULOMB_POT_H
#include "Potential.h"

class Coulomb_pot: public Potential {
public:
    Coulomb_pot();
    Coulomb_pot(int n_particles, int dim, double charge);
    virtual ~Coulomb_pot();
    double evaluate( double** );
private:
};

#endif	/* COULOMB_POT_H */

