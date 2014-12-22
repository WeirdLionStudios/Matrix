#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/**
* Author: Trek
*
* Commits:
* 22/12/14 Venio
* -Better output
* -Variable operand size
* -Fixed wrong results
**/

//Print the matrix under a header, passing the header, the matrix and its
//dimensions
void print_matrix(const char* header, int** matrix, int width, int height);

//Max size of the elements
#define size 10

unsigned int m1, n1, m2, n2;

int main(){
	
	cout<<"Enter the dimensions of A separated by a space"<<endl;
	cin>>m1>>n1;

	cout<<"Enter the dimensions of B separated by a space"<<endl;
	cin>>m2>>n2;

	if(n1!=m2){
		cout<<"Invalid matrix size!"<<endl;
		return 1;
	}

	cout<<pow(2, 31)<<endl;
    
    int a[m1][n1];
    int b[m2][n2];
    int c[m1][n2];
    
    srand(time(NULL));
    
    for(int m=0;m<m1;m++){
        for(int n=0;n<n1;n++){
            a[m][n]=rand()%size;
        }
    }
    
    for(int n=0;n<m2;n++){
        for(int p=0;p<n2;p++){
            b[n][p]=rand()%size;
        }
    }
    
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
			c[i][j]=0;
            for(int index=0;index<n1;index++){
                c[i][j]+=a[i][index]*b[index][j];
            }
        }
    }

	cout<<"A"<<endl;
	for(int i=0;i<m1;i++){
		cout<<"\t";
        	for(int j=0;j<n1;j++)
        	        cout<<a[i][j]<<"\t";
       		cout<<endl;
	}
	cout<<endl;

	cout<<"B"<<endl;
	for(int i=0;i<m2;i++){
		cout<<"\t";
        	for(int j=0;j<n2;j++)
        	        cout<<b[i][j]<<"\t";
       		cout<<endl;
	}
	cout<<endl;
	
	cout<<"C=A*B"<<endl;
	for(int i=0;i<m1;i++){
		cout<<"\t";
        	for(int j=0;j<n2;j++)
        	        cout<<c[i][j]<<"\t";
       		cout<<endl;
	}
    
    system("PAUSE");
    return 0;    
}
