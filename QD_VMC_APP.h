/* 
 * File:   QD_VMC_APP.h
 * Author: sigve
 *
 * Created on 13. februar 2012, 10:01
 */

#ifndef QD_VMC_APP_H
#define	QD_VMC_APP_H

#include "QVMC.h"

class QD_VMC_APP {
public:
    QD_VMC_APP();
    virtual ~QD_VMC_APP();
    
    void QD_run_VMC();
protected:    
    // Functions
    void QD_write_to_file( char* );
    
    // Variabels
    QVMC*** paramset;
    int dim; 
    int n_particles;
    int mc_cycles;
    double w;         
    int a_steps;
    double a_start, delta_a;
    int b_steps;
    double b_start, delta_b;
    
    int sampling;
    bool write_to_file;
    bool jastrow;
};

#endif	/* QD_VMC_APP_H */

