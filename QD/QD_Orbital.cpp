/* 
 * File:   QD_Orbital.cpp
 * Author: sigve
 * 
 * Created on 1. mars 2012, 09:30
 */

#include "QD_Orbital.h"

/*******************************************************************
 * 
 * NAME :               QD_Orbital( double** r)
 *
 * DESCRIPTION :        Constructor.
 * 
 */
QD_Orbital::QD_Orbital(int dim, double alpha, double w) : w(w), Orbital(dim, alpha) {
    sqrt_w_alpha = sqrt(w * alpha);
    w_alpha = w*alpha;
    sqrt_w = sqrt(w);
}

/*******************************************************************
 * 
 * NAME :               evaluate( double** r)
 *
 * DESCRIPTION :        Evaluates the orbital at the coordinate r.
 * 
 */
double QD_Orbital::evaluate(rowvec r, int nx, int ny) {
    double Hx = H->polynomial(nx, sqrt_w_alpha * r(0));
    double Hy = H->polynomial(ny, sqrt_w_alpha * r(1));

    return Hx * Hy * exp(evaluate_exp(r));
}

/*******************************************************************
 * 
 * NAME :               eval_simple( double** r)
 *
 * DESCRIPTION :        Evaluates the orbital in the coordinate r.
 * 
 */
double QD_Orbital::evaluate_exp(rowvec r) {
    return -0.5 * w_alpha * dot(r, r);
}

/*******************************************************************
 * 
 * NAME :               evaluate_laplacian( rowvec r, int nx, int ny )
 *
 * DESCRIPTION :        Evaluates the Laplacian in the coordinate r.
 * 
 */

double QD_Orbital::evaluate_laplacian(rowvec r, int nx, int ny) {
    double sum = 0;

    double Hx = H->polynomial(nx, sqrt_w_alpha * r(0));
    double Hy = H->polynomial(ny, sqrt_w_alpha * r(1));

    if (nx > 1)
        sum += 4.0 * nx * (nx - 1) * H->polynomial(nx - 2, sqrt_w_alpha * r(0)) / Hx;

    if (ny > 1)
        sum += 4.0 * ny * (ny - 1) * H->polynomial(ny - 2, sqrt_w_alpha * r(1)) / Hy;

    if (nx > 0)
        sum -= 4.0 * sqrt_w_alpha * nx * r(0) * H->polynomial(nx - 1, sqrt_w_alpha * r(0)) / Hx;

    if (ny > 0)
        sum -= 4 * sqrt_w_alpha * ny * r(1) * H->polynomial(ny - 1, sqrt_w_alpha * r(1)) / Hy;

    sum += w_alpha * dot(r, r) - 2;
    sum *= w_alpha;

    return sum * evaluate(r, nx, ny);
}

/*******************************************************************
 * 
 * NAME :               compute_gradient(mat r)
 *
 * DESCRIPTION :        Computes the total Jasrow Wavefunction's 
 *                      gradient in r.
 * 
 */
rowvec QD_Orbital::get_gradient(rowvec r, int nx, int ny) {
    rowvec gradient = zeros(1, dim);

    double Hx = H->polynomial(nx, sqrt_w_alpha * r(0));
    double Hy = H->polynomial(ny, sqrt_w_alpha * r(1));

    // x-component.
    if (nx > 0)
        gradient(0) = 2 * nx * sqrt_w_alpha * H->polynomial(nx - 1, sqrt_w_alpha * r(0)) / Hx;

    // y-component.
    if (ny > 0)
        gradient(1) = 2 * ny * sqrt_w_alpha * H->polynomial(ny - 1, sqrt_w_alpha * r(1)) / Hy;

    gradient -= w_alpha*r;

    return gradient * evaluate(r, nx, ny);
}