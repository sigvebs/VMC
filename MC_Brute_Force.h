/* 
 * File:   MC_Brute_Force.h
 * Author: sigve
 *
 * Created on 17. februar 2012, 14:43
 */

#ifndef MC_Brute_Force_H
#define	MC_Brute_Force_H
#include "QVMC.h"

class MC_Brute_Force : public QVMC {
public:
    MC_Brute_Force();
    MC_Brute_Force(Hamiltonian*, Wavefunction*, int, long);

    void mc_sampling(int, double, int&, double&, double&);
    virtual void solve();
    double optimal_step_length();
    double difference(double);
protected:
    double step_length;
};

#endif	/* MC_Brute_Force_H */

