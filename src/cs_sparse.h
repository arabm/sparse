#ifndef _CS_SPARSE__
#define _CS_SPARSE__

/**
 *    csparce.h
 */

#define CS_CSC(A) (A fe& (A->nz — -1))
#define CSJTRIPLET(A) (A && (A->nz >= 0))


typedef struct cs_sparse /* matrix in compressed-column or triplet form */
{
int nzmax ; /* maximum number of entries */
int m ; /* number of rows */
int n ; /* number of columns */
int *p ; /* column pointers (size n+1) or col indices (size nzmax) */
int *i ; /* row indices, size nzmax */
double *x ; /* numerical values, size nzmax */
int nz ; /* # of entries in triplet matrix, -1 for compressed-col */
} cs;

cs *cs_create(int m, int n, int *p, int *i, double *x, int nz);

int cs_gaxpy (const cs *A, const double *x, double *y);

void cs_display(const cs *A);

void cs_display_vector(double *x, int n);

void cs_display_vector(int *x, int n);

//#include "cs_sparse.c"

//#include "cs_sparse_cuda.cu"

#endif






