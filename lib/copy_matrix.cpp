#include <matrix_common.h>

//Copy the contents of a matrix to another
void copy_matrix(double** src, double** dest, int dim){
	for(int i=0;i<dim;i++)
		for(int j=0;j<dim;j++)
			dest[i][j]=src[i][j];
}

