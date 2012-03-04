/* 
 * File:   Slater.h
 * Author: sigve
 *
 * Created on 1. mars 2012, 09:16
 */

#ifndef SLATER_H
#define	SLATER_H

#include <armadillo>
using namespace arma;

#include "Orbital.h";

class Slater {
public:
    Slater(int, int, double);
    void set_matrix();
    double get_det();
    void set_position(mat);
    double get_laplacian(int);
    void compute_gradient(int);

    rowvec get_gradient() {
        return gradient;
    };
    void compute_inverse();
private:
    Orbital *orbital;
    double w; // Check
    mat r_current; // Check
    mat Dp; // Check
    mat Dm; // Check
    mat inverse_Dp; // Check
    mat inverse_Dm; // Check
    ivec nx;
    ivec ny;
    int dim; // Check
    int N; // Check

    rowvec gradient;
};

#endif	/* SLATER_H */

