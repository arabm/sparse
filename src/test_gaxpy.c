


#include "cs_sparse.h"
#include "cs_sparse_cuda.cuh"


#include "stdio.h"

int main(int argv, char **argc){

    char test_title[] = " Test Gaxpy\n";
    printf(" %s", test_title);
    
    /*
        Size of the matrix
    */
    int m = 4;
    int n = 4;
    int nz = -1;
    int nzmax = 10;
    
    int p[] = {0,3,6,8,10};
    int i[] = {0,1,3,1,2,3,0,2,1,3};
    double x[]= {4.5, 3.1, 3.5, 2.9, 1.7,
		0.4, 3.2, 3.0, 0.9, 1.0};
    
    cs M;
    M.p = p;
    M.i = i;
    M.x = x;
    M.m = m;
    M.n = n;
    M.nz = nz;
    
    
    double v0[]={ 1, 2, 3,4};
    
    double v1[]={ 1, 2, 3,4};
    
    cs_gaxpy(&M,v0,v1);
    
    
    printf("Hello World\n");


    return 0;
}
