/* 
 * File:   Kinetic.h
 * Author: sigve
 *
 * Created on 8. februar 2012, 17:06
 */

#ifndef KINETIC_H
#define	KINETIC_H
#include "Wavefunction.h"

class Kinetic {
public:
    Kinetic(int, int);
    Kinetic(const Kinetic& orig);
    virtual ~Kinetic();
    
    void set_wf( Wavefunction* wf){ this->wf = wf;};
    virtual double evaluate( double** ) = 0;
protected:
    int n_particles;
    int dim;
    Wavefunction* wf;
};

#endif	/* KINETIC_H */

