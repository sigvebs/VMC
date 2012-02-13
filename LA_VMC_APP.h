/* 
 * File:   LA_VMC_APP.h
 * Author: sigve
 *
 * Created on 13. februar 2012, 10:10
 */

#ifndef LA_VMC_APP_H
#define	LA_VMC_APP_H

class LA_VMC_APP {
public:
    LA_VMC_APP();
    virtual ~LA_VMC_APP();
    
    void LA_run_VMC();
private:
    int dim; 
    int n_particles;
    int mc_cycles;
    double a, b, charge; 
};

#endif	/* LA_VMC_APP_H */

