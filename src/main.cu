


#include "umfcu_sparse.h"

#include "umfcu_sparse_cuda.cuh"

#include "umfcu_util.h"
#include "umfcu_memory.h"

#include "stdio.h"


int main(int argv, char **argc){

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
    
    cs *M;
    M = cs_spalloc(m,n,nzmax,1,0);
    memcpy(M->i,i,nzmax*sizeof(int));
    memcpy(M->p,p,(n+1)*sizeof(int));
    memcpy(M->x,x,nzmax*sizeof(double));
    
  /*  
    M.p = p;
    M.i = i;
    M.x = x;
    M.m = m;
    M.n = n;
	M.nzmax = nzmax;
    M.nz = nz;*/
    
 	printf( "cs M\n");
	cs_display(M);
  
 
    double v0[]={ 1, 2, 3,4};
    
    double v1[]={ 0, 0, 0,0};
    double v2[]={ 0, 0, 0,0};

	printf ("cs V0\n");
	cs_display_vector(v0,n);
 
	printf ("cs v1\n");
	cs_display_vector(v1,n);   

	clock_t begin;
	clock_t end;
	double time_elapsed;
	cs_measuring_time(&begin);
    cs_gaxpy(M,v0,v1);
	cs_measuring_time(&end);

	cs_measuring_time_elapsed(&begin,&end,&time_elapsed);
	printf(" CPU : %f\n",time_elapsed);
	

	printf ("cs v1\n");
	cs_display_vector(v1,n);   

	
	cs_measuring_time(&begin);
	cs_gaxpy_cuda(M,v0,v2);
	cs_measuring_time(&end);

	cs_measuring_time_elapsed(&begin,&end,&time_elapsed);
	printf(" GPU : %f\n",time_elapsed);
    
 	printf ("cs v2\n");
	cs_display_vector(v2,n);   

    cs_spfree(M);
  
	


    return 0;
}
