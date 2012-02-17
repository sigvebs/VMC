/* 
 * File:   QD_MC_Brute_Force.h
 * Author: sigve
 *
 * Created on 17. februar 2012, 14:43
 */

#ifndef QD_MC_BRUTE_FORCE_H
#define	QD_MC_BRUTE_FORCE_H
#include "QVMC.h"

class QD_MC_Brute_Force : public QVMC {
public:
    QD_MC_Brute_Force();
    QD_MC_Brute_Force(Hamiltonian*, Wavefunction*, int, long);
    virtual ~QD_MC_Brute_Force();

    virtual void mc_sampling(int, double, int&, double&, double&);
    virtual void solve();
    virtual double optimal_step_length();
    virtual double difference(double);
protected:
};

#endif	/* QD_MC_BRUTE_FORCE_H */

