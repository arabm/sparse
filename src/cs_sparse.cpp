#include "stdlib.h"
#include "stdio.h"

#include "cs_sparse.h"

cs *cs_create(int m, int n, int *p, int *i, double *x, int nz){

    cs *cs_c = (cs*) malloc(sizeof(cs));
    cs_c->i = (int*) malloc((n+1)*sizeof(int));
    cs_c->p = (int*) malloc( (nz)*sizeof(int));
    return cs_c;
};

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

