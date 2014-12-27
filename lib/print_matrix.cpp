#include <matrix_common.h>

void print_matrix(char* header, double** matrix, int dim){
	cout<<header<<endl;
	int i, j;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
