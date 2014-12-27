#include <matrix_common.h>

void init_rand_matrix(double** ptr, int dim, int max){
	srand(time(NULL));
	int i, j;
	for(i=0;i<dim;i++)
		for(j=0;j<dim;j++)
			ptr[i][j]=rand()%max;
}
