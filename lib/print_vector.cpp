#include <matrix_common.h>

//Prints the contents of a vector with a header
void print_vector(string header, double* vector, int dim){
	cout<<header<<endl;
	int i;
	for(i=0;i<dim;i++)
		cout<<vector[i]<<endl;
	cout<<endl;
}
