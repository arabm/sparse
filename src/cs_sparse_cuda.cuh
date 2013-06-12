#ifndef _CS_SPARSE_CUDA__
#define _CS_SPARSE_CUDA__


#include <cuda.h>
#include <cuda_runtime.h>

#include "cs_sparse.h"


int cs_gaxpy_cuda(const cs *A, const double *x, double *y);

__global__ void cs_gaxpy_cuda_kernel(const cs A, const double *x, double *y);

__device__ void cs_gaxpy_cuda_device(const cs *A, const double *x, double *y);


#endif
