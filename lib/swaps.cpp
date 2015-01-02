#include <matrix_common.h>

//Swaps two columns
void swap_col(double** matrix, int dim, int col1, int col2){
	int temp;
	for(int i=0;i<dim;i++){
		temp=matrix[i][col1];
		matrix[i][col1]=matrix[i][col2];
		matrix[i][col2]=temp;
	}
}

//Swaps two rows
void swap_row(double** matrix, int dim, int row1, int row2){
	int temp;
	for(int i=0;i<dim;i++){
		temp=matrix[row1][i];
		matrix[row1][i]=matrix[row2][i];
		matrix[row2][i]=temp;
	}
}

