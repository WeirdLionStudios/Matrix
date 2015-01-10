#include <iostream>
#include <cstdlib>
#include <matrix_common.h>

//get the transposed matrix by swapping rows and columns
double** transpose_matrix(double** matrix, int dx, int dy){
	
	double** transposed_matrix;
	transposed_matrix=new double*[dx];
	for(int i=0;i<dx;i++)
		transposed_matrix[i]=new double[dy];

	for(int i=0;i<dy;i++){
		for(int j=0;j<dx;j++){
			transposed_matrix[i][j]=matrix[j][i];		
		}
	}
	return transposed_matrix;
}
