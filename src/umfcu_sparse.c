#include "stdlib.h"
#include "stdio.h"




/*
*/
int cs_gaxpy (const cs *A, const double *x, double *y){
    int i,j,n = A->n,*Ai = A->i,*Ap = A->p;
    
    const double *Ax = A->x;
    
    for (j = 0; j< n ; j++){
        for (i = Ap[j]; i < Ap[j+1]; i++){
            y[ Ai[i] ] += Ax[i]*x[j];
        }
    }
    return 0;
};


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            

