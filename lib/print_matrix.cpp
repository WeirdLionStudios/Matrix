#include <matrix_common.h>

//Prints the contents of a matrix with a header
void print_matrix(string header, double** matrix, int dim){
	cout<<header<<endl;
	int i, j;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
