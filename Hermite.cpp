/* 
 * File:   Hermite.cpp
 * Author: sigve
 * 
 * Created on 29. februar 2012, 18:45
 */

#include "Hermite.h"

Hermite::Hermite() {
}

double Hermite::polynomial(int degree, double x){
    double hermite_polynomial;
    
    if( degree == 0)
        hermite_polynomial = 1;
    else if(degree == 1)
        hermite_polynomial = 2*x;
    else if(degree == 2)
        hermite_polynomial = 4*x*x -2;
    else if(degree == 3)
        hermite_polynomial = 8*x*x*x -12;
    else
        hermite_polynomial = 0;    
    
    return hermite_polynomial;
}