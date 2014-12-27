#include <matrix_common.h>

void print_vector(char* header, double* vector, int dim){
	cout<<header<<endl;
	int i;
	for(i=0;i<dim;i++)
		cout<<vector[i]<<endl;
	cout<<endl;
}
