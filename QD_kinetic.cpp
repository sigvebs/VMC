/* 
 * File:   QD_kinetic.cpp
 * Author: sigve
 * 
 * Created on 9. februar 2012, 12:21
 */

#include "QD_kinetic.h"
#include "lib.h"

QD_kinetic::QD_kinetic( int dim, int n_particles, double w ): Kinetic( dim, n_particles ){
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
double QD_kinetic::evaluate( double** r ){
#if 1
    double a, b; // TMP
    double r1, r2, r12, r1_dot_r2;
    double e_kin;
    // TMP
    a = 0.987;
    b = 0.398;
    
    // Finding distances r1, r2 and r12
    r1 = r2 = r12 = 0;
    for(int i=0; i<dim; i++){
            r1 += r[0][i]*r[0][i];
            r2 += r[1][i]*r[1][i];
            r12 += (r[0][i] - r[1][i])*(r[0][i] - r[1][i]);
            //r1_dot_r2 +=  r[0][i]*r[1][i];
    }
    
    r1 = sqrt(r1);
    r2 = sqrt(r2);
    r12 = sqrt(r12);
    double u = 1+b*r12;
    double bb = u*u;
    e_kin = -1.0/r12 - 1./bb + 2*b/u + w*a*r12;
    e_kin /= ((1+b*r12)*(1+b*r12));
    e_kin += 2*a*w;
    e_kin -= 0.5*a*a*w*w*(r1*r1 + r2*r2);
    
    return e_kin;
    
    // the step length and its squared inverse for the second derivative 
#else
    
#define h 0.001
#define h2 1000000
  int i, j;
  
  double wfminus, wfplus, wfold, e_kinetic;
  double **r_plus, **r_minus;
  
  wfold = wf->evaluate( r );
  
  // allocate matrices which contain the position of the particles  
  // the function matrix is defined in the progam library 
  r_plus = (double **) matrix( n_particles, dim, sizeof(double));
  r_minus = (double **) matrix( n_particles, dim, sizeof(double));
  
  for (i = 0; i < n_particles; i++) { 
    for ( j=0; j < dim; j++) {
      r_plus[i][j] = r_minus[i][j] = r[i][j];
    }
  }

  // compute the kinetic energy  
  e_kinetic = 0;
  for (i = 0; i < n_particles; i++) {
    for (j = 0; j < dim; j++) { 
      r_plus[i][j] = r[i][j]+h;
      r_minus[i][j] = r[i][j]-h;
      wfminus = wf->evaluate( r_minus ); 
      wfplus  = wf->evaluate( r_plus); 
    
      e_kinetic -= (wfminus+wfplus-2*wfold);
      r_plus[i][j] = r[i][j];
      r_minus[i][j] = r[i][j];
    }
  }

  // Freeing memory
  free_matrix( (void**) r_plus );
  free_matrix( (void**) r_minus );
  
  // include electron mass and hbar squared and divide by wave function 
  e_kinetic = 0.5*h2*e_kinetic/wfold;
  return e_kinetic;
#endif
}
