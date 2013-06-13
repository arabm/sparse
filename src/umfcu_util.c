
#include "stdio.h"

void cs_display(const cs *A){

    double *Ax = A->x;
    int *Ap = A->p, *Ai = A->i, n = A->n, m= A->m;
    int row,column;
    int i,j,k;
    int find = 0;
    for (i = 0 ; i < m; i++) {
        for ( j = 0; j< n ; j++){
            for ( k = Ap[j]; k < Ap[j+1]; k++){
		    if (Ai[k] == i){
			    printf("%.1f ", Ax[k]);
			    find = 1;
		    }
	    }
	    if (!find)
		    printf("0.0 ");	
	    find = 0;
	
        }

	    printf("\n");
    }

};

void cs_display_vector(double *x, int n){
	int i;
	for ( i = 0 ; i <n ; i++)
		printf("%.1f\n",x[i]);



};

void cs_display_vector(int *x, int n){
	int i;
	for ( i = 0 ; i <n ; i++)
		printf("%d\n",x[i]);
};
