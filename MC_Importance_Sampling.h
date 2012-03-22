/* 
 * File:   MC_Importance_Sampling.h
 * Author: sigve
 *
 * Created on 17. februar 2012, 15:20
 */

#ifndef MC_Importance_Sampling_H
#define	MC_Importance_Sampling_H
#include "QVMC.h"

class MC_Importance_Sampling: public QVMC {
public:
    MC_Importance_Sampling(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum);
    virtual ~MC_Importance_Sampling();
    
    // Functions
    virtual void solve();
    void run_importance_sampling(int, int&, double&, double&);
 
protected:
    double dt;    
    float fn[128];
    int kn[128];
    float wn[128];
    double D;
    double gaussian_deviate(long * idum);
};

#endif	/* MC_Importance_Sampling_H */

