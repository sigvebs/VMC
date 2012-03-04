/* 
 * File:   electron_interaction.h
 * Author: sigve
 *
 * Created on 8. februar 2012, 18:32
 */

#ifndef ELECTRON_INTERACTION_H
#define	ELECTRON_INTERACTION_H

#include "Interaction.h"

class electron_interaction: public Interaction {
public:
    electron_interaction(int, int);
    
    virtual double evaluate( mat );
private:

};

#endif	/* ELECTRON_INTERACTION_H */

