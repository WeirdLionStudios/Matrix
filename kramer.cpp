/**
 * Kramer method
 * 
 * @author Venio
 * 
 * translation from Java code by Trek
 */

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

	srand(time(NULL));

	double** coeff;
	double** b_coeff;
	double* ans;
	double* res;
	double det, b_det;

	coeff=new double*[dim];
	for(int i=0;i<dim;i++)
		coeff[i]=new double[dim];

	b_coeff=new double*[dim];
	for(int i=0;i<dim;i++)
		b_coeff[i]=new double[dim];

	ans=new double[dim];
	res=new double[dim];

	init_rand_matrix(coeff, dim, MAX);
	print_matrix("Given matrix: ", coeff, dim);

	for(int i=0;i<dim;i++)
		ans[i]=rand()%MAX;

	det=get_laplace_determinant(coeff, dim);

	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			copy_matrix(coeff, b_coeff, dim);
			b_coeff[j][i]=ans[j];
		}
		b_det=get_laplace_determinant(b_coeff, dim);
		res[i]=b_det/det;
		cout<<"Calculation: \n"<<b_det<<" / "<<det<<" = "<<res[i]<<"\n\n";
	}

	print_vector("Result: ", res, dim);

}

