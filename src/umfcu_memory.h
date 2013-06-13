#ifndef __UMFCU_MEMORY__
#define __UMFCU_MEMORY__

/*
    umfcu_memory.h
*/

void *cs_malloc(int n, size_t size);

void *cs_calloc(int n, size_t size);

void *cs_free(void *p);

void *cs_realloc(void *p, int n, size_t size, int *ok);


cs *cs_spalloc(int m, int n, int nzmax, int values, int triplet);

cs *cs_spfree(cs *A);

cs *cs_sprealloc (cs *A, int nzmax);

#include "umfcu_memory.c"

#endif
