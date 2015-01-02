#include <matrix_common.h>

//Copies the contents of a vector to another
void copy_vector(double* src, double* dest, int dim){
	for(int i=0;i<dim;i++)
		dest[i]=src[i];
}
