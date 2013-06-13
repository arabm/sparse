#ifndef __UMFCU_SPARSE_CUDA__
#define __UMFCU_SPARSE_CUDA__


#include <cuda.h>
#include <cuda_runtime.h>

#include "umfcu_sparse.h"


int cs_gaxpy_cuda(const cs *A, const double *x, double *y);

__global__ void cs_gaxpy_cuda_kernel(const cs A, const double *x, double *y);

__device__ void cs_gaxpy_cuda_device(const cs *A, const double *x, double *y);


void cs_measuring_time(clock_t *time);

void cs_measuring_time_elapsed(clock_t *begin, clock_t *end,double *out);

#include "umfcu_sparse_cuda.cu"

#endif
