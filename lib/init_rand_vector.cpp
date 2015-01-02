#include <matrix_common.h>

//Populates a vector with random numbers from 0(inclusive) to max(exclusive)
void init_rand_vector(double* ptr, int dim, int max){
	ptr=new double[dim];
	srand(time(NULL));
	int i;
	for(i=0;i<dim;i++)
		ptr[i]=rand()%max;
}
