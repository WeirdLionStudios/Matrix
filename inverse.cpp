/**
*
* Author: Trek
*
**/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <matrix_common.h>

using namespace std;

#define MAX 10

int dim;

int main(){
	cout<<"Insert matrix's dimension:"<<endl;
	cin>>dim;

	if(dim<1){
		cout<<"ERROR: The dimension of the matrix must be >=1!"<<endl;
		return 1;
	}
	
	double** inv;
	double** a;
	double** cofactor;
	double** transposed;
	double** submatrix;

	a=new double*[dim];
	for(int i=0;i<dim;i++)
		a[i]=new double[dim];
		
	cofactor=new double*[dim];
	for(int i=0;i<dim;i++)
		cofactor[i]=new double[dim];
	
	inv=new double*[dim];
	for(int i=0;i<dim;i++)
		inv[i]=new double[dim];

	transposed=new double*[dim];
	for(int i=0;i<dim;i++)
		transposed[i]=new double[dim];	

	submatrix=new double*[dim-1];
	for(int k=0;k<dim-1;k++)
		submatrix[k]=new double[dim-1];

	init_rand_matrix(a, dim, dim, MAX);
	print_matrix("Given matrix: ", a, dim, dim);

	double detA=get_laplace_determinant(a, dim);
	if(a==0){
		cout<<"Determinant is equal to 0. Given matrix is not invertible."<<endl;
		return 0;	
	}
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){

			submatrix=get_submatrix(a, dim, dim, i, j);

			cofactor[i][j]=pow(-1, i+j)*get_laplace_determinant(submatrix, dim-1);
		}
	}

	transposed=transpose_matrix(cofactor, dim, dim);

	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){	
			inv[i][j]=transposed[i][j]/detA;
		}
	}
	print_matrix("Inverted matrix: ", inv, dim, dim);
}
