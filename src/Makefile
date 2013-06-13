#######
#
#
#######


CC = gcc
CXX = g++
NCC = nvcc



CCFLAGS = -O2
XXFLAGS = -O2 
NCCFLAGS = 

# Cuda Flags
CUDAPATH = /usr/local/cuda-5.0
CUDAINCLUDE = -I$(CUDAPATH)/include
CUDAFLAGS =  -L$(CUDAPATH)/lib64 

# Boost Librairie
BOOSTPATH = /home/hubeco2/lib/boost_1_53_0
BOOSTINCLUDE = -I$(BOOSTPATH)

EXEC = main.out
OBJ = umfcu_sparse.o umfcu_sparse_cuda.o

all : $(EXEC)



%.out : %.o
	$(NCC) -o $@ $^ $(CCFLAGS) 
	
%.o : %.cu 
	$(NCC) -c $^ -o $@ $(NCCFLAGS) -arch=sm_30

%.o : %.cpp 
	$(CXX) -c $^ -o $@ $(XXFLAGS) $(CUDAINCLUDE) $(BOOSTINCLUDE)
	
%.o : %.c
	$(CC) -c $^ -o $@ $(CCFLAGS) $(CUDAINCLUDE)



	
clean : 
	rm -f *.o && rm -f *~

realclean :
	make clean && rm -f $(EXEC)
