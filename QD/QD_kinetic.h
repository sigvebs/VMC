/* 
 * File:   QD_kinetic.h
 * Author: sigve
 *
 * Created on 9. februar 2012, 12:21
 */

#ifndef QD_KINETIC_H
#define	QD_KINETIC_H

#include "../Kinetic.h"

class QD_kinetic: public Kinetic {
public:
    QD_kinetic(int ,int ,double );    
    virtual double evaluate( mat );
private:
    double w;
};

#endif	/* QD_KINETIC_H */

