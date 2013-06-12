


#include "cs_sparse_cuda.cuh"

#include "stdio.h"

int cs_gaxpy_cuda(const cs *A, const double *x, double *y){
    int n = A->n,m = A->m, *Ai = A->i,*Ap = A->p, nzmax = A->nzmax;
    
    const double *Ax = A->x;
  
	 cs dA;
	memcpy(&dA,A,sizeof(cs));

	cudaMalloc(&(dA.p), (n+1)*sizeof(int));
	cudaMemcpy(dA.p,Ap,(n+1)*sizeof(int),cudaMemcpyHostToDevice);

	cudaMalloc(&(dA.i), nzmax*sizeof(int));
	cudaMemcpy(dA.i,Ai,nzmax*sizeof(int),cudaMemcpyHostToDevice);
	
	cudaMalloc(&(dA.x), nzmax*sizeof(double));
	cudaMemcpy(dA.x,Ax,nzmax*sizeof(double),cudaMemcpyHostToDevice);
		
	double *dx;
	cudaMalloc(&dx,sizeof(double)*n);
	cudaMemcpy(dx,x,sizeof(double)*n,cudaMemcpyHostToDevice);
	double *dy;
	cudaMalloc(&dy,sizeof(double)*n);
	cudaMemcpy(dy,y,sizeof(double)*n,cudaMemcpyHostToDevice);

    dim3 sGrid(1,1,1);
    dim3 sBloc(m,1,1);
    
	cs_gaxpy_cuda_kernel<<<sGrid,sBloc>>>(dA,dx,dy);

	cudaMemcpy(y,dy,sizeof(double)*n,cudaMemcpyDeviceToHost);
	cudaFree(dx);
	cudaFree(dy);
	cudaFree(dA.i);
	cudaFree(dA.p);
	cudaFree(dA.x);
	cudaFree(&dA);
//	cudaDeviceReset();
    return 0;
};



__global__ void cs_gaxpy_cuda_kernel(const cs A, const double *x, double *y){

	__shared__ double sy[10];
    int idx = threadIdx.x + blockIdx.x*blockDim.x;
    int idy = threadIdx.y + blockIdx.y*blockDim.y;
    
    int j,n = A.n,m=A.m, *Ai = A.i,*Ap = A.p;
    const double *Ax = A.x;
   
	if (idx<10){
		sy[idx]=y[idx];
	}
	__syncthreads();

    double tmp = 0;
	int indice = 0; 
	for (j = 0; j < n;j++){
		indice = idx+Ap[j];
		if (indice < Ap[j+1]){
	            	sy[Ai[indice]] +=  Ax[indice]*x[j];
	        }
		__syncthreads();
	}
	
	if (idx <10){
		y[idx] = sy[idx];
	}
	__syncthreads();
    
    

//    cs_gaxpy_cuda_device(A,x,y); /* Call device function */

};

__device__ void cs_gaxpy_cuda_device(const cs *A, const double *x, double *y){

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
    int idy = threadIdx.y + blockIdx.y*blockDim.y;
    
    int i,j,n = A->n,m=A->m, *Ai = A->i,*Ap = A->p;
    const double *Ax = A->x;
  
  printf("Hello thread %d\n", threadIdx.x); 
	double tmp = 0; 
    if ( idx < m){
	for (j = 0; j < n;j++){
	        for (i = Ap[j]; i < Ap[j+1]; i++){
			if (idy == Ai[i])
	            		tmp += Ax[i]*x[idy];
	        }
	}
	y[idy] = 1;//tmp;
    }

};
