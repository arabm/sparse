#ifndef __UMFCU_UTIL__
#define __UMFCU_UTIL__

void cs_display(const cs *A);

void cs_display_vector(double *x, int n);

void cs_display_vector(int *x, int n);


double cs_cumsum( int *p, int *c, int n);

#include "umfcu_util.c"

#endif
