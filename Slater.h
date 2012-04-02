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
    Slater(int, int, Orbital*);
    void update_matrix();
    void set_position(mat, int);
    double get_laplacian(int);
    void compute_gradient(int);
    double get_ratio();
    rowvec get_gradient() {
        return gradient;
    };
    void update_inverse();
    void accept_new_position();
    void init();
protected:
    Orbital *orbital;
    double w;
    mat r_new;
    mat r_old;
    
    mat Dp; 
    mat Dm; 
    mat Dp_new;
    mat Dm_new;
    mat Dp_inv; 
    mat Dm_inv;
    mat Dp_inv_new; 
    mat Dm_inv_new;
    
    ivec nx;
    ivec ny;
    int dim; 
    int N; 
    int n_particles;
    int active_particle;

    rowvec gradient;
};

#endif	/* SLATER_H */

