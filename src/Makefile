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

CUDAPATH = /usr/local/cuda-5.0
CUDAINCLUDE = -I$(CUDAPATH)/include
CUDAFLAGS =  -L$(CUDAPATH)/lib64 


EXEC = main.out
OBJ = cs_sparse.o cs_sparse_cuda.o

all : $(EXEC)

%.out : %.o
	$(CC) -o $@ $^ $(CCFLAGS) 
	
%.o : %.cu 
	$(NCC) -c $^ -o $@ $(NCCFLAGS) -arch=sm_30

%.o : %.cpp 
	$(CXX) -c $^ -o $@ $(XXFLAGS) $(CUDAINCLUDE)
	
%.o : %.c
	$(CC) -c $^ -o $@ $(CCFLAGS) $(CUDAINCLUDE)


main.out : $(OBJ) main.o
	$(CXX) $(CUDAFLAGS) -o $@ $^ $(CCFLAGS) -lcuda -lcudart
	
clean : 
	rm -f *.o && rm -f *~

realclean :
	make clean && rm -f $(EXEC)
