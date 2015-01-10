/**
* Gaussian determinant
*
* Author: Venio
**/

#include <matrix_common.h>

#include <iostream>
#include <math.h>

using namespace std;

#define MAX 10

void get_nonzero(int r, int c);

//Number of swapped rows and columns
int r_swap=0, c_swap=0;

//The determinant is certainly 0 if true
bool zero;

//The determinant
double det;

//Size of the matrix
int dim;
//The matrix variable
double** a;

int main(){
	cout<<"Insert the matrix dimensions"<<endl;
	cin>>dim;

	if(dim<1){
		cout<<"The dimension of the matrix must be >=1"<<endl;
		return 1;
	}

	a=new double*[dim];
	for(int i=0;i<dim;i++)
		a[i]=new double[dim];

	//Random values and display
	init_rand_matrix(a, dim, dim, MAX);
	print_matrix("A", a, dim, dim);

	//Iterate on submatrixes by ignoring the first row and column each time
	for(int i=0;i<dim-1;i++){
		//Make sure the pivot is not 0
		get_nonzero(i, i);
		//If there isn't a suitable pivot, it's useless to continue
		if(zero)
			break;
		//Subtract to each row the first one multiplied by its first
		//element
		for(int j=i+1;j<dim;j++){
			double m=a[j][i];
			for(int k=i;k<dim;k++){
				a[j][k]-=a[i][k]*m/a[i][i];
			}
		}
		print_matrix("Next step", a, dim, dim);
	}

	if(zero) det=0;
	//Calculate determinant from the triangular matrix
	else{
		det=1;
		for(int i=0;i<dim;i++)
			det*=a[i][i];
		det*=pow(-1, c_swap+r_swap);
	}
	//Show output
	print_matrix("Final matrix", a, dim, dim);
	cout<<"Gauss determinant:\t"<<det<<endl;
}

//Get a nonzero value to the desired position in the matrix, by swapping
//rows and columns
void get_nonzero(int row, int col){
	bool is_nonzero=false;
	for(int i=col;i<dim;i++){
		for(int j=row;j<dim;j++)
			//If the element is not 0
			if(a[j][i]){
				is_nonzero=true;
				//If statements necessary for not swapping a row
				//or a column with itself
				if(j!=row){
					swap_row(a, dim, dim, j, row);
					r_swap++;
					cout<<"Swapping rows "<<row
						<<" and "<<j<<endl;
					print_matrix("", a, dim, dim);
				}
				if(i!=col){
					swap_col(a, dim, dim, i, col);
					c_swap++;
					cout<<"Swapping cols "<<col
						<<" and "<<i<<endl;
					print_matrix("", a, dim, dim);
				}
				break;
			}
		if(is_nonzero) break;
	}
	//Didn't find a suitable non-zero element
	if(!is_nonzero) zero=true;
}
