
#include "umfcu_define.h"

void *cs_malloc(int n, size_t size){

    return malloc(CS_MAX(n,1)*size);
};

void *cs_calloc(int n, size_t size){
    return calloc(CS_MAX(n,1),size);
};

void *cs_free(void *p){
    if (p) free(p);
    return NULL;

};

void *cs_realloc(void *p, int n, size_t size, int *ok){
    void *pnew;
    pnew = realloc(p, CS_MAX(n,1)*size);
    *ok = (pnew != NULL);
    return ((*ok)?pnew :p);
};


cs *cs_spalloc(int m, int n, int nzmax, int values, int triplet){
    cs *A = (cs *) cs_calloc(1, sizeof(cs));
    if (!A) return NULL;
    A->m = m;
    A->n = n;
    A->nzmax = nzmax = CS_MAX(nzmax,1);
    A->nz = triplet ? 0 : -1;
    A->p = (int*) cs_malloc(triplet? nzmax : n+1, sizeof(int));
    A->i = (int*) cs_malloc(nzmax, sizeof(int));
    A->x =  values ? (double*) cs_malloc(nzmax, sizeof(double)):NULL;
    return ((!A->p || !A->i || (values && !A->x )) ? cs_spfree(A) : A);

};

cs *cs_spfree(cs *A){
    if (!A) return NULL;
    cs_free(A->i);
    cs_free(A->p);
    cs_free(A->x);
    return ( (cs*) cs_free(A));
};

cs *cs_sprealloc (cs *A, int nzmax){


};
