#include <iostream>
#include <cstdlib>

#include <matrix_common.h>

using namespace std;

double determinant(double** matrix);

#define MAX 10

int dim;

int main(){
	cout<<"Inserire la dimensione della matrice"<<endl;
	cin>>dim;

	if(dim<2) cout<<"Invalid matrix size"<<endl;
	
	double** a;
	a=new double*[dim];
	for(int i=0;i<dim;i++)
		a[i]=new double[dim];
	
	init_rand_matrix(a, dim, MAX);

	print_matrix("A", a, dim);

	cout<<"Determinant: "<<get_laplace_determinant(a, dim)<<endl;
}
