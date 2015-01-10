#include <matrix_common.h>

//Prints the contents of a matrix with a header
void print_matrix(string header, double** matrix, int dx, int dy){
	cout<<header<<endl;
	int i, j;
	for(i=0;i<dy;i++){
		for(j=0;j<dx;j++)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
