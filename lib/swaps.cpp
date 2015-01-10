#include <matrix_common.h>

//Swaps two columns
void swap_col(double** matrix, int dx, int dy, int col1, int col2){
	int temp;
	for(int i=0;i<dy;i++){
		temp=matrix[i][col1];
		matrix[i][col1]=matrix[i][col2];
		matrix[i][col2]=temp;
	}
}

//Swaps two rows
void swap_row(double** matrix, int dx, int dy, int row1, int row2){
	int temp;
	for(int i=0;i<dx;i++){
		temp=matrix[row1][i];
		matrix[row1][i]=matrix[row2][i];
		matrix[row2][i]=temp;
	}
}

