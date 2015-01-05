#include <matrix_common.h>

//Get the determinant of a matrix using laplace expansion
double get_laplace_determinant(double** a, int dim){
	double det=0;
	if(dim==2)
		return a[0][0]*a[1][1]-a[0][1]*a[1][0];
	int i;
	for(i=0;i<dim;i++)
		det+=a[0][i]*get_laplace_determinant(
				get_submatrix(a, dim, 0, i),
				dim-1)*pow(-1, i);
	return det;
}

//Get the submatrix of a matrix by removing a row and a column
double** get_submatrix(double** matrix, int dim, int row, int col){
	int i, j;
	double** sub;
	sub=new double*[dim-1];
	for(int i=0;i<dim-1;i++)
		sub[i]=new double[dim-1];
	int c, r=0;
	for(i=0;i<dim;i++){
		c=0;
		if(i==row)
			continue;
		for(j=0;j<dim;j++)
			if(j!=col)
				sub[r][c++]=matrix[i][j];
		r++;
	}
	return sub;
}

