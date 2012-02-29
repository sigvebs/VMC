/* 
 * File:   qd_wavefunction.h
 * Author: sigve
 *
 * Created on 9. februar 2012, 09:26
 */

#ifndef QD_WAVEFUNCTION_H
#define	QD_WAVEFUNCTION_H
#include "Wavefunction.h"

class QD_wavefunction: public Wavefunction {
public:
    QD_wavefunction( int, int, double, double, double, bool );
    
    virtual double eval_simple( double**, int );
    virtual double get_simple_gradient( double**, int, int );
private:
    double w;
};

#endif	/* QD_WAVEFUNCTION_H */

