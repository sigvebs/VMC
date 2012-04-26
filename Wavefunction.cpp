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

    energy = 0;
    slater = new Slater(dim, n_particles, orbital);

    r_old = zeros(n_particles, dim);
    r_new = zeros(n_particles, dim);
}

/*******************************************************************
 * 
 * NAME :               get_ratio();
 *
 * DESCRIPTION :        Returns the R-ratio used in the Metropolis 
 *                      test.
 * 
 */
double Wavefunction::get_ratio() {
    double R = slater->get_ratio();

    if (jastrow) {
        R *= jas->get_ratio(r_new, r_old);
    }
    return R;
}

/*******************************************************************
 * 
 * NAME :               evaluate(mat r)
 *
 * DESCRIPTION :        Used for numerical derivates to evaulate the WF in r.
 * 
 */

double Wavefunction::evaluate(mat r) {
    double psi;

    psi = slater->evaluate(r);

    // Adding the Jastrow part
    if (jastrow)
        psi *= exp(jas->evaluate(r));

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

mat Wavefunction::q_force() {
    mat q_f = zeros(n_particles, dim);

    //#if NUMERICAL  
#if 0
    double h = 0.05;

    mat r_plus = zeros(n_particles, dim);
    mat r_minus = zeros(n_particles, dim);

    // Initiating r_plus and r_minus.
    r_plus = r_new;
    r_minus = r_new;

    // Calculating the Quantum Force numerically.
    for (int i = 0; i < n_particles; i++) {
        for (int j = 0; j < dim; j++) {
            r_plus(i, j) += h;
            r_minus(i, j) -= h;
            q_f(i, j) = 2 * (evaluate(r_plus) - evaluate(r_minus)) / (2 * h * evaluate(r_new));
            r_plus(i, j) = r_new(i, j);
            r_minus(i, j) = r_new(i, j);
        }
    }
#else
    rowvec gradient_slater;
    rowvec gradient_jastrow;
    double R = slater->get_ratio();
    
    for (int i = 0; i < n_particles; i++) {

        // Finding the Orbitals' gradient.
        slater->compute_gradient(i);
        gradient_slater = slater->get_gradient();

        // Finding the Jastrow's gradient.
        jas->compute_gradient(r_new, i);
        gradient_jastrow = jas->get_gradient();

        q_f.row(i) = 2 * (gradient_jastrow + gradient_slater)/R;
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
    slater->set_position(r_new, active_particle);
    slater->update_matrix();
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
    slater->update_inverse();
    slater->accept_new_position();
    calculate_laplacian();
}

/*******************************************************************
 * 
 * NAME :               set_r_new(mat r_new)
 *
 * DESCRIPTION :        Sets a new position.
 * 
 */
void Wavefunction::set_r_new(mat r_new, int active_particle) {
    this->r_new = r_new;
    this->active_particle = active_particle;
}

/*******************************************************************
 * 
 * NAME :               init_slater()
 *
 * DESCRIPTION :        Initializes the Slater matrix with 
 *                      the initial position matrix.
 * 
 */
void Wavefunction::init_slater() {
    slater->set_position(r_new, active_particle);
    slater->init();
}

/*******************************************************************
 * 
 * NAME :               calculate_laplacian(mat r)
 *
 * DESCRIPTION :        Calculates the Laplcian.
 * 
 */
void Wavefunction::calculate_laplacian() {

    energy = 0;

    // Looping through all particles
    for (int i = 0; i < n_particles; i++) {
        // Finding the Orbitals' Laplacian.
        slater->compute_gradient(i);
        energy += slater->get_laplacian(i);

        // Finding the Jastrow factors Laplacian
        jas->compute_gradient(r_old, i);
        energy += jas->get_laplacian(r_old, i);

        // Dot product between the gradients of the orbital- and Jastrow function.
        rowvec gradient_orbital = slater->get_gradient();
        rowvec gradient_jastrow = jas->get_gradient();

        energy += 2 * dot(gradient_orbital, gradient_jastrow);
    }
}