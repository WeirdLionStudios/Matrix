/**
*
* Author: Trek
*
**/

#include <iostream>
#include <cstdlib>

#include <matrix_common.h>

using namespace std;

#define MAX 10

int dim;

int main(){
	cout<<"Inserire la dimensione della matrice"<<endl;
	cin>>dim;

	if(dim<1){
		cout<<"The dimension of the matrix must be >=1"<<endl;
		return 1;
	}
	
	double** a;
	a=new double*[dim];
	for(int i=0;i<dim;i++)
		a[i]=new double[dim];
	
	init_rand_matrix(a, dim, MAX);

	print_matrix("A", a, dim);
}
