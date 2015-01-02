#include <matrix_common.h>

//Populates a matrix with random numbers between 0(inclusive) and max(exclusive)
void init_rand_matrix(double** ptr, int dim, int max){
	srand(time(NULL));
	for(int i=0;i<dim;i++)
		for(int j=0;j<dim;j++)
			ptr[i][j]=rand()%max;
}
