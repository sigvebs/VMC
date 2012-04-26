/* 
 * File:   Blocking.h
 * Author: sigve
 *
 * Created on 7. april 2012, 15:43
 */

#ifndef BLOCKING_H
#define	BLOCKING_H

#include <armadillo>
using namespace arma;

class Blocking {
public:
    Blocking();
    vec block(vec, int, int);
private:
};

#endif	/* BLOCKING_H */

