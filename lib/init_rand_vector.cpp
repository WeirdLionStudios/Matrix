#include <matrix_common.h>

void init_rand_vector(double* ptr, int dim, int max){
	srand(time(NULL));
	int i;
	for(i=0;i<dim;i++)
		ptr[i]=rand()%max;
}
