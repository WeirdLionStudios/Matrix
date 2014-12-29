#include <iostream>
#include <cstdlib>

using namespace std;

int determinant(int** matrix);

#define MAX 10

int dim;

int main(){
	cout<<"Inserire la dimensione della matrice"<<endl;
	cin>>dim;

	if(dim<2) cout<<"Invalid matrix size"<<endl;
	
	int** a;
	a=new int*[dim];
	for(int i=0;i<dim;i++)
		a[i]=new int[dim];

	int i, j;

	//Random values
	srand(time(NULL));
	for(i=0;i<dim;i++)
		for(j=0;j<dim;j++)
			a[i][j]=rand()%MAX;

	//Print matrix
	cout<<"A"<<endl;
	for(int i=0;i<dim;i++){
		cout<<"\t";
        	for(int j=0;j<dim;j++)
        	        cout<<a[i][j]<<"\t";
       		cout<<endl;
	}
	cout<<endl;

	int det=determinant(a);
	
	cout<<"Determinant: "<<det<<endl;
}

int determinant(int** matrix){
	int det=0;
	int dh, dl;
	for(int i=0;i<dim;i++){
		dh=1;
		dl=1;
		for(int j=0;j<dim;j++){
			dh*=matrix[j][(i+j)%dim];
			dl*=matrix[j][(i-j+((i<j)?dim:0))%dim];
		}
		det+=dh-dl;
	}
	return det;
}
