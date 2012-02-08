/* 
 * File:   Kinetic_electron.h
 * Author: sigve
 *
 * Created on 8. februar 2012, 18:49
 */

#ifndef KINETIC_ELECTRON_H
#define	KINETIC_ELECTRON_H
#include "Kinetic.h"

class Kinetic_electron: public Kinetic {
public:
    Kinetic_electron( int, int, double );
    virtual ~Kinetic_electron();
    
    virtual double evaluate( double** );
private:

};

#endif	/* KINETIC_ELECTRON_H */

