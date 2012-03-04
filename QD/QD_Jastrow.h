/* 
 * File:   QD_Jastrow.h
 * Author: sigve
 *
 * Created on 29. februar 2012, 17:29
 */

#ifndef QD_JASTROW_H
#define	QD_JASTROW_H
#include "../Jastrow.h"
#include "../defines.h";

class QD_Jastrow : public Jastrow {
public:
    QD_Jastrow(int, int, double);
    virtual double evaluate(mat);
    virtual void compute_gradient(mat, int);
    virtual double get_laplacian(mat, int);
protected:
    mat a;
};

#endif	/* QD_JASTROW_H */

