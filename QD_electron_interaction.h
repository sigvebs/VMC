/* 
 * File:   QD_electron_interaction.h
 * Author: sigve
 *
 * Created on 3. mars 2012, 17:08
 */

#ifndef QD_ELECTRON_INTERACTION_H
#define	QD_ELECTRON_INTERACTION_H
#include "Interaction.h"

class QD_electron_interaction: public Interaction {
public:
    QD_electron_interaction(int, int);
    
    virtual double evaluate( mat );
private:

};

#endif	/* QD_ELECTRON_INTERACTION_H */

