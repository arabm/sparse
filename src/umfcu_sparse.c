#include "stdlib.h"
#include "stdio.h"

#include "umfcu_define.h"

#include "umfcu_memory.h"
#include "umfcu_util.h"

int cs_entry (cs *T, int i, int j, double x){
	if (!CS_TRIPLET(T) || i < 0 || j < 0) return 0;
	if (T->nz >= T->nzmax && !cs_sprealloc(T,2*(T->nzmax))) return 0;
	if (T->x) T->x[T->nz] = x;
	T->i [T->nz] = i;
	T->p [T->nz++] = j;
	T->m = CS_MAX(T->m, i+1);
	T->n = CS_MAX(T->n, j+1);
	return 1;
};

cs *cs_compress(const cs *T){
	int m, n, nz, p, k, *Cp, *Ci, *w, *Ti, *Tj;
	double *Cx, *Tx ;
	cs * C;
	if (!CS_TRIPLET(T)) return NULL;
	m = T->m;
	n = T->n;
	Ti = T->i;
	Tj = T->p;
	Tx = T->x;
	nz = T->nz;
	w = (int*) cs_calloc(n,sizeof(int));
	C = cs_spalloc(m,n,nz, Tx != NULL, 0);
	Cp = C->p;
	Ci = C->i;
	Cx = C->x;
	for (k = 0; k < nz ; k++) w[ Tj[k]]++;
	cs_cumsum(Cp,w,n);
	for (k = 0; k < nz ; k++){
		Ci[p = w[Tj[k]++]] = Ti[k] ;
		if (Cx) Cx[p] = Tx[k];
	}
	return cs_done(C,w,NULL,1);

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



