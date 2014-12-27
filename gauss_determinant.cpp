/**
* Gaussian determinant
*
* Author: Venio
**/

/**
* WARNING: DOESN'T DO ANYTHING (yet...)
**/

#include <matrix_common.h>

#include <iostream>

using namespace std;

#define MAX 10

int dim;
double** a;

int main(){
	cout<<"Insert the matrix dimensions"<<endl;
	cin>>dim;

	int i, j, k, l;
	a=new double*[dim];
	for(i=0;i<dim;i++)
		a[i]=new double[dim];

	//Random values and display
	init_rand_matrix(a, dim, MAX);
	print_matrix((char*)"A", a, dim);
}
