/* 
 * File:   Interaction.h
 * Author: sigve
 *
 * Created on 8. februar 2012, 17:07
 */

#ifndef INTERACTION_H
#define	INTERACTION_H

class Interaction {
public:
    Interaction(int dim, int n_particles,  double charge );
    Interaction(const Interaction& orig);
    virtual ~Interaction();
    
    virtual double evaluate( double** r) = 0;
protected:
    int n_particles;
    int dim;
    double charge;

};

#endif	/* INTERACTION_H */

