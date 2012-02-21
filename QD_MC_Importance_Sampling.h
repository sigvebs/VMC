/* 
 * File:   QD_MC_Importance_Sampling.h
 * Author: sigve
 *
 * Created on 17. februar 2012, 15:20
 */

#ifndef QD_MC_IMPORTANCE_SAMPLING_H
#define	QD_MC_IMPORTANCE_SAMPLING_H
#include "QVMC.h"

class QD_MC_Importance_Sampling: public QVMC {
public:
    QD_MC_Importance_Sampling(Hamiltonian* ht, Wavefunction* wf, int mc_cycles, long idum);
    virtual ~QD_MC_Importance_Sampling();
    
    // Functions
    virtual void solve();
    void ic_sampling(int, int&, double&, double&);
 
protected:
    double dt;    
    float fn[128];
    int kn[128];
    float wn[128];
    double D;
    double gaussian_deviate(long * idum);
};

#endif	/* QD_MC_IMPORTANCE_SAMPLING_H */

