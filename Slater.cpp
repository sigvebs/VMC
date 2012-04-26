/* 
 * File:   Slater.cpp
 * Author: sigve
 * 
 * Created on 1. mars 2012, 09:16
 */

#include <iostream>
#include "Slater.h"

/*******************************************************************
 * 
 * NAME :               Slater(int dim, int n_particles, double alpha)
 * 
 *
 * DESCRIPTION :        Constructor.
 * 
 */
Slater::Slater(int dim, int n_particles, Orbital *orbital)
: dim(dim), N(n_particles / 2), n_particles(n_particles), orbital(orbital) {

    Dp = zeros(N, N);
    Dm = zeros(N, N);
    Dp_new = zeros(N, N);
    Dm_new = zeros(N, N);
    Dp_inv = zeros(N, N);
    Dm_inv = zeros(N, N);
    Dp_inv_new = zeros(N, N);
    Dm_inv_new = zeros(N, N);

    // Computing the Quantum Numbers.
    nx.set_size(N);
    ny.set_size(N);
    int l = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            nx(l) = i - j;
            ny(l) = j;
            l++;
            // Breaking the loop if we have enough numbers.
            if (l == N)
                i = j = N;
        }
    }

}

/*******************************************************************
 * 
 * NAME :               init(); 
 * 
 *
 * DESCRIPTION :        Initializes the Slater matrix with position 
 *                      values.
 * 
 */
void Slater::init() {

    // Updating the whole matrix.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Dp(j, i) = orbital->evaluate(r_new.row(i), nx(j), ny(j));
            Dm(j, i) = orbital->evaluate(r_new.row(i + N), nx(j), ny(j));
        }
    }
    Dp_new = Dp;
    Dm_new = Dm;

    // Calulating the inverse using Armadillo.
    Dp_inv = inv(Dp).t();
    Dm_inv = inv(Dm).t();

    Dp_inv_new = Dp_inv;
    Dm_inv_new = Dm_inv;
}

/*******************************************************************
 * 
 * NAME :               get_ratio(); 
 * 
 *
 * DESCRIPTION :        Returns the R ratio: R_D = |D_new|/|D_old|
 * 
 */
double Slater::get_ratio() {
    double R = 0;
    int i = active_particle;

    if (i < N) { // Spin up
        for (int j = 0; j < N; j++) {
            R += Dp_new(j, i) * Dp_inv(j, i);
        }
    } else {
        for (int j = 0; j < N; j++) {
            R += Dm_new(j, i - N) * Dm_inv(j, i - N);
        }
    }
    return R;
}

/*******************************************************************
 * 
 * NAME :               update_inverse(); 
 * 
 *
 * DESCRIPTION :        Updates the inverse matrix for the 
 *                      active particle.
 * 
 */
void Slater::update_inverse() {

    int i = active_particle;
    Dp_inv_new = Dp_inv;
    Dm_inv = Dm_inv_new;

    double S;
    // TMP solution for the inverse.

    double R = get_ratio();

    if (i < N) { // Spin up
        for (int j = 0; j < N; j++) {
            if (j != i) {
                S = 0;
                for (int l = 0; l < N; l++)
                    S += Dp_new(l, i) * Dp_inv(l, j);
            }
            for (int l = 0; l < N; l++)
                Dp_inv_new(l, j) = Dp_inv(l, j) - (Dp_inv(l, i) / R) * S;
        }
        for (int l = 0; l < N; l++)
            Dp_inv_new(l, i) = Dp_inv(l, i) / R;
    } else { // Spin down
        for (int j = 0; j < N; j++) {
            if (j != i - N) {
                S = 0;
                for (int l = 0; l < N; l++)
                    S += Dm_new(l, i - N) * Dm_inv(l, j);
            }
            for (int l = 0; l < N; l++)
                Dm_inv_new(l, j) = Dm_inv(l, j) - (Dm_inv(l, i - N) / R) * S;
        }
        for (int l = 0; l < N; l++)
            Dm_inv_new(l, i - N) = Dm_inv(l, i - N) / R;
    }

}

/*******************************************************************
 * 
 * NAME :               set_position(mat r, int active_particle)  
 *
 *
 * DESCRIPTION :        Sets the position.
 * 
 */
void Slater::set_position(mat r, int active_particle) {
    this->active_particle = active_particle;
    r_new = r;
}

/*******************************************************************
 * 
 * NAME :               update_matrix()  
 * 
 *
 * DESCRIPTION :        Updates the Slater matrix with the 
 *                      coordinates of the active particle.
 * 
 */
void Slater::update_matrix() {
    if (active_particle < N) {
        for (int i = 0; i < N; i++) {
            Dp_new(i, active_particle) = orbital->evaluate(r_new.row(active_particle), nx(i), ny(i));
        }
    } else {
        for (int i = 0; i < N; i++) {
            Dm_new(i, active_particle - N) = orbital->evaluate(r_new.row(active_particle), nx(i), ny(i));
        }
    }
}

/*******************************************************************
 * 
 * NAME :               accept_new_position()  
 * 
 *
 * DESCRIPTION :        Updates old matrices with the new WF and inverse.
 * 
 */
void Slater::accept_new_position() {

    if (active_particle < N) {
        for (int i = 0; i < N; i++)
            Dp(i, active_particle) = Dp_new(i, active_particle);
        Dp_inv = Dp_inv_new;
    } else {
        for (int i = 0; i < N; i++)
            Dm(i, active_particle - N) = Dm_new(i, active_particle - N);
        Dm_inv = Dm_inv_new;
    }
}

/*******************************************************************
 * 
 * NAME :               get_laplace()  
 * 
 *
 * DESCRIPTION :        The functions calculates the Laplacian of 
 *                      particle i and returns the result.
 * 
 */
double Slater::get_laplacian(int i) {

    double sum = 0;
    if (i < N) {
        for (int j = 0; j < N; j++) { // Spin up.
            sum += orbital->evaluate_laplacian(r_new.row(i), nx(j), ny(j)) * Dp_inv(j, i);
        }
    } else {
        for (int j = 0; j < N; j++) { // Spin down.
            sum += orbital->evaluate_laplacian(r_new.row(i), nx(j), ny(j)) * Dm_inv(j, i - N);
        }
    }

    return sum;
}

/*******************************************************************
 * 
 * NAME :               compute_gradient()  
 * 
 *
 * DESCRIPTION :        The functions calculates the gradient of 
 *                      particle i and stores it in the global 
 *                      variable gradient.
 * 
 */
void Slater::compute_gradient(int i) {
    gradient = zeros(1, dim);

    if (i < N) {
        for (int j = 0; j < N; j++) { // Spin up.
            gradient += orbital->get_gradient(r_new.row(i), nx(j), ny(j)) * Dp_inv(j, i);
        }
    } else {
        for (int j = 0; j < N; j++) { // Spin down.
            gradient += orbital->get_gradient(r_new.row(i), nx(j), ny(j)) * Dm_inv(j, i - N);
        }
    }
}

/*******************************************************************
 * 
 * NAME :               evaluate(mat r)  
 * 
 *
 * DESCRIPTION :        Returns the determinant of D(r) using 
 *                      Armadillos determinant function. This
 *                      function is used if we have to evaluate
 *                      the WF in unrelated new coordinates.
 * 
 */
double Slater::evaluate(mat r) {
    mat D_p = zeros(N, N);
    mat D_m = zeros(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D_p(j, i) = orbital->evaluate(r.row(i), nx(j), ny(j));
            D_m(j, i) = orbital->evaluate(r.row(i + N), nx(j), ny(j));
        }
    }

    return det(D_p) * det(D_m);
}