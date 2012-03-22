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
: dim(dim), N(n_particles / 2), orbital(orbital) {

    Dp = zeros(N, N);
    Dm = zeros(N, N);
    inverse_Dp = zeros(N, N);
    inverse_Dm = zeros(N, N);

    // Computing the Quantum Numbers.
    nx.set_size(N);
    ny.set_size(N);
    int l = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            nx(l) = i - j;
            ny(l) = j;
            l++;
            // Breaking the loop if the we have enough numbers.
            if (l == N)
                i = j = N;
        }
    }

}

/*******************************************************************
 * 
 * NAME :               set_position(double **r)  
 * 
 *
 * DESCRIPTION :        Sets the position.
 * 
 */
void Slater::set_position(mat r) {
    r_current = r;
}

/*******************************************************************
 * 
 * NAME :               set_matrix(double **r)  
 * 
 *
 * DESCRIPTION :        caluculates the values of all the orbitals.
 * 
 */
void Slater::set_matrix() {
    // Updating the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Dp(i, j) = orbital->evaluate(r_current.row(j), nx(i), ny(i));
            Dm(i, j) = orbital->evaluate(r_current.row(j + N), nx(i), ny(i));
        }
    }
}

/*******************************************************************
 * 
 * NAME :               get_det()  
 * 
 *
 * DESCRIPTION :        Returns the determinant of the slater matrix.
 * 
 */
void Slater::compute_inverse() {
    try {
        inverse_Dp = inv(Dp);
        inverse_Dm = inv(Dm);

    } catch (const std::runtime_error &e) {
        cout << r_current << endl;
        cout << "Dp" << endl;
        cout << Dp << endl;
        cout << "Dm" << endl;
        cout << Dm << endl;
        exit(0);
    }
}

/*******************************************************************
 * 
 * NAME :               get_det()  
 * 
 *
 * DESCRIPTION :        Returns the determinant of the slater matrix.
 * 
 */
double Slater::get_det() {
    return det(Dp) * det(Dm);
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
        for (int j = 0; j < N; j++) { // For DP
            sum += orbital->evaluate_laplacian(r_current.row(i), nx(j), ny(j)) * inverse_Dp(i, j);
        }
    } else {
        for (int j = 0; j < N; j++) { // For Dm
            sum += orbital->evaluate_laplacian(r_current.row(i), nx(j), ny(j)) * inverse_Dm(i - N, j);
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
        for (int j = 0; j < N; j++) { // For DP
            gradient += orbital->get_gradient(r_current.row(i), nx(j), ny(j)) * inverse_Dp(i, j);
        }
    } else {
        for (int j = 0; j < N; j++) { // For Dm
            gradient += orbital->get_gradient(r_current.row(i), nx(j), ny(j)) * inverse_Dm(i - N, j);
        }
    }
}