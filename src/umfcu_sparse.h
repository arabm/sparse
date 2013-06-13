#ifndef __UMFCU_SPARSE__
#define __UMFCU_SPARSE__

/**
 *    csparce.h
 */




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


int cs_entry (cs *T, int i, int j, double x);

int cs_gaxpy (const cs *A, const double *x, double *y);



#include "umfcu_sparse.c"



#endif






