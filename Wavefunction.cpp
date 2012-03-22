/* 
 * File:   Wavefunction.cpp
 * Author: Sigve
 * 
 * Created on February 4, 2012, 10:55 PM
 */

#include "Wavefunction.h"

#include <math.h>
#include "includes/lib.h"
#include "defines.h"

/*******************************************************************
 * 
 * NAME :               Wavefunction(int dim, int n_particles, 
 *                      double alpha, double beta, bool jastrow)
 *
 * DESCRIPTION :        Constructor
 * 
 */
Wavefunction::Wavefunction(int dim, int n_particles, double alpha, double beta, bool jastrow, Orbital* orbital, Jastrow* jas)
: dim(dim), n_particles(n_particles), alpha(alpha), beta(beta), jastrow(jastrow), orbital(orbital), jas(jas) {
    
    slater = new Slater(dim, n_particles, orbital);

    r_old = zeros <mat > (n_particles, dim);
    r_new = zeros <mat > (n_particles, dim);
}

/*******************************************************************
 * 
 * NAME :               evaluate(mat r)
 *
 * DESCRIPTION :        Used for numerical derivates to evaulate the WF in r.
 * 
 */

double Wavefunction::evaluate(mat r) {

    // Calulating the Slater determinant.
    slater->set_position(r);
    slater->set_matrix();
    double psi = slater->get_det();

    // Adding the Jastrow part
    if (jastrow) {
        psi *= jas->evaluate(r);
    }

    return psi;
}

/*******************************************************************
 * 
 * NAME :               q_force(mat r)  
 * 
 *
 * DESCRIPTION :        q_force returns a matrix with the total 
 *                      quantum force on the particles.
 * 
 */

mat Wavefunction::q_force(mat r) {
    mat q_f = zeros<mat > (n_particles, dim);
    
#if NUMERICAL
    double h = 0.05;
    
    mat r_plus = zeros<mat > (n_particles, dim);
    mat r_minus = zeros<mat > (n_particles, dim);

    // Initiating r_plus and r_minus.
    r_plus = r;
    r_minus = r;

    // Calculating the Quantum Force numerically.
    
    for (int i = 0; i < n_particles; i++) {
        for (int j = 0; j < dim; j++) {
            r_plus(i, j) += h;
            r_minus(i, j) -= h;
            q_f(i, j) = 2 * (evaluate(r_plus) - evaluate(r_minus)) / (2 * h * evaluate(r));
            r_plus(i, j) = r(i, j);
            r_minus(i, j) = r(i, j);
        }
    }
#else
    slater->compute_inverse();

    for (int i = 0; i < n_particles; i++) {
        // Finding the Orbitals' Laplacian.
        slater->compute_gradient(i);
        jas->compute_gradient(r, i);
        
        rowvec gradient_orbital = slater->get_gradient();
        rowvec gradient_jastrow = jas->get_gradient();
        
        q_f.row(i) = 2 * (gradient_orbital + gradient_jastrow) ;
    }
#endif
    return q_f;
}

/*******************************************************************
 * 
 * NAME :               evaluate_new()
 *
 * DESCRIPTION :        evalutates the wave function in the new position.
 * 
 */
void Wavefunction::evaluate_new() {
    // Calulating the Slater determinant.
    slater->set_position(r_new);
    slater->set_matrix();
    WF_new = slater->get_det();

    // Adding the Jastrow part
    if (jastrow)
        WF_new *= jas->evaluate(r_new);
}

/*******************************************************************
 * 
 * NAME :               accept_move()
 *
 * DESCRIPTION :        The new move is accepted.
 * 
 */
void Wavefunction::accept_move() {
    r_old = r_new;
    WF_old = WF_new;
}

/*******************************************************************
 * 
 * NAME :               set_r_new(mat r_new)
 *
 * DESCRIPTION :        Sets a new position.
 * 
 */
void Wavefunction::set_r_new(mat r_new) {
    this->r_new = r_new;
}

/*******************************************************************
 * 
 * NAME :               get_laplacian(mat r)
 *
 * DESCRIPTION :        Returns the Laplacian. Right now it returns 
 *                      the kinetic energy - except for the -0.5 factor.
 * 
 */
double Wavefunction::get_laplacian(mat r) {

    // TMP combining all terms here.
    double sum = 0;

    slater->set_position(r);
    slater->set_matrix();
    slater->compute_inverse();

    // Looping through all particles
    for (int i = 0; i < n_particles; i++) {
        // Finding the Orbitals' Laplacian.
        slater->compute_gradient(i);
        sum += slater->get_laplacian(i);

        // Finding the Jastrow factors Laplacian
        jas->compute_gradient(r, i);
        sum += jas->get_laplacian(r, i);

        // Dot product between the gradients of the orbital- and Jastrow function.
        rowvec gradient_orbital = slater->get_gradient();
        rowvec gradient_jastrow = jas->get_gradient();

        sum += 2 * dot(gradient_orbital, gradient_jastrow);
    }
    return sum;
}