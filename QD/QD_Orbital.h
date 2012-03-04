/* 
 * File:   QD_Orbital.h
 * Author: sigve
 *
 * Created on 1. mars 2012, 09:30
 */

#ifndef QD_ORBITAL_H
#define	QD_ORBITAL_H
#include "../Orbital.h"

class QD_Orbital : public Orbital {
public:
    QD_Orbital(int, double, double);
    virtual double evaluate(rowvec, int, int);
    virtual double evaluate_exp(rowvec );
    virtual double evaluate_laplacian(rowvec, int, int);
    virtual rowvec get_gradient(rowvec, int, int);
protected:
    double w;
    double sqrt_w;
    double w_alpha;
    double sqrt_w_alpha;
};

#endif	/* QD_ORBITAL_H */

