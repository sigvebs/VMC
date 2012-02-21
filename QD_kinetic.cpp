/* 
 * File:   QD_kinetic.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 12:21
 */

#include "QD_kinetic.h"
#include "lib.h"

QD_kinetic::QD_kinetic(int dim, int n_particles, double w) : Kinetic(dim, n_particles) {
    this->w = w;
}

QD_kinetic::~QD_kinetic() {
}

/*******************************************************************
 * 
 * NAME :               evaluate( double* r)
 *
 * DESCRIPTION :        In progress.
 * 
 */
double QD_kinetic::evaluate(double** r) {
    // Analytic solution without the Jastrow fasctor.
#if 0
    double alpha, r_sq, derivative;
    alpha = wf->getAlpha();

    derivative = 0;
    for( int i = 0; i < n_particles; i++){
        r_sq = 0;   
        for (int j = 0; j < dim; j++) {
            r_sq += r[i][j] * r[i][j];
        }
        derivative += -2 * w * alpha + (w * w) * (alpha * alpha)*r_sq;
    }

    return -0.5 * derivative;
#endif

    // Analytic solution with the Jastrow factor.
#if 1
    double a, b;
    double u, bb;
    double r1, r2, r12;
    double e_kin;

    a = wf->getAlpha();
    b = wf->getBeta();

    // Finding distances r1, r2 and r12
    r1 = r2 = r12 = 0;
    for (int i = 0; i < dim; i++) {
        r1 += r[0][i] * r[0][i];
        r2 += r[1][i] * r[1][i];
        r12 += (r[0][i] - r[1][i])*(r[0][i] - r[1][i]);
    }

    r1 = sqrt(r1);
    r2 = sqrt(r2);
    r12 = sqrt(r12);

    u = 1 + b*r12;
    bb = u*u;

    e_kin = -1.0 / r12 - 1. / bb + 2 * b / u + w * a*r12;
    e_kin /= ((1 + b * r12)*(1 + b * r12));
    e_kin += 2 * a*w;
    e_kin -= 0.5 * a * a * w * w * (r1 * r1 + r2 * r2);

    return e_kin;
#else
    // the step length and its squared inverse for the second derivative 
    double h = 0.001;
    int i, j;

    double wfminus, wfplus, wfold, e_kinetic;
    double **r_plus, **r_minus;

    wfold = wf->evaluate(r);

    // allocate matrices which contain the position of the particles  
    // the function matrix is defined in the progam library 
    r_plus = (double **) matrix(n_particles, dim, sizeof (double));
    r_minus = (double **) matrix(n_particles, dim, sizeof (double));

    for (i = 0; i < n_particles; i++) {
        for (j = 0; j < dim; j++) {
            r_plus[i][j] = r_minus[i][j] = r[i][j];
        }
    }

    // compute the kinetic energy  
    e_kinetic = 0;
    for (i = 0; i < n_particles; i++) {
        for (j = 0; j < dim; j++) {
            r_plus[i][j] = r[i][j] + h;
            r_minus[i][j] = r[i][j] - h;
            wfminus = wf->evaluate(r_minus);
            wfplus = wf->evaluate(r_plus);

            e_kinetic += (wfplus - 2 * wfold + wfminus);
            r_plus[i][j] = r[i][j];
            r_minus[i][j] = r[i][j];
        }
    }

    // Freeing memory
    free_matrix((void**) r_plus);
    free_matrix((void**) r_minus);

    // include electron mass and hbar squared and divide by wave function 
    e_kinetic = -0.5 * e_kinetic / (h * h) / wfold;
    return e_kinetic;
#endif
}
