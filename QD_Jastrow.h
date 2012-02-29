/* 
 * File:   QD_Jastrow.h
 * Author: sigve
 *
 * Created on 29. februar 2012, 17:29
 */

#ifndef QD_JASTROW_H
#define	QD_JASTROW_H
#include "Jastrow.h"

class QD_Jastrow : public Jastrow {
public:
    QD_Jastrow(int, int, double);
    virtual double evaluate(double**);
    virtual double get_gradient(double**, int, int);
protected:

};

#endif	/* QD_JASTROW_H */

