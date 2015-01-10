#include <matrix_common.h>

//Populates a matrix with random numbers between 0(inclusive) and max(exclusive)
void init_rand_matrix(double** ptr, int dx, int dy, int max){
	srand(time(NULL));
	for(int i=0;i<dy;i++)
		for(int j=0;j<dx;j++)
			ptr[i][j]=rand()%max;
}
