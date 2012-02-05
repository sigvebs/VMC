/* 
 * File:   Helium.h
 * Author: sigve
 *
 * Created on 5. februar 2012, 11:03
 */

#ifndef HELIUM_H
#define	HELIUM_H
#include "Wavefunction.h"

class Helium: public Wavefunction
{
public:
    Helium();
    Helium( int, int, double, double );
    Helium(const Helium& orig);
    virtual ~Helium();
    
    double evaluate( double** );
    double get_energy( double** );
private:

};

#endif	/* HELIUM_H */

