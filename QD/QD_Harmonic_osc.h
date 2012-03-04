/* 
 * File:   Harmonic_osc.h
 * Author: sigve
 *
 * Created on 9. februar 2012, 09:03
 */

#ifndef HARMONIC_OSC_H
#define	HARMONIC_OSC_H
#include "../Potential.h"

class QD_Harmonic_osc : public Potential {
public:
    QD_Harmonic_osc(int, int, double);

    virtual double evaluate(mat);
private:
    double w;
};

#endif	/* HARMONIC_OSC_H */

