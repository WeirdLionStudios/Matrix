#include <matrix_common.h>

//Copy the contents of a matrix to another
void copy_matrix(double** src, double** dest, int dx, int dy){
	for(int i=0;i<dy;i++)
		for(int j=0;j<dx;j++)
			dest[i][j]=src[i][j];
}

