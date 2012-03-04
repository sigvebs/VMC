/* 
 * File:   Interaction.h
 * Author: sigve
 *
 * Created on 8. februar 2012, 17:07
 */

#ifndef INTERACTION_H
#define	INTERACTION_H

#include <armadillo>
using namespace arma;

class Interaction {
public:
    Interaction(int dim, int n_particles);

    virtual double evaluate(mat) = 0;
protected:
    int n_particles;
    int dim;
};

#endif	/* INTERACTION_H */

