#include <iostream>
#include <cstdlib>
#include <matrix_common.h>

//get the transposed matrix by swapping rows and columns
double** transpose_matrix(double** matrix, int dim){
	
	double** transposed_matrix;
	transposed_matrix=new double*[dim];
	for(int i=0;i<dim;i++)
		transposed_matrix[i]=new double[dim];

	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			transposed_matrix[i][j]=matrix[j][i];		
		}
	}
	return transposed_matrix;
}
