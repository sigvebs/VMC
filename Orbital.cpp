/* 
 * File:   Orbital.cpp
 * Author: sigve
 * 
 * Created on 1. mars 2012, 09:27
 */

#include <math.h>
#include "Orbital.h"

/*******************************************************************
 * 
 * NAME :               Orbital( )
 *
 * DESCRIPTION :        Constructor.
 * 
 */
Orbital::Orbital(int dim, double alpha) : dim(dim), alpha(alpha) {
    H = new Hermite();
}
