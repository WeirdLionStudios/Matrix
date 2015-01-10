#include <cstdlib>
#include <iostream>
#include <time.h>

#include <matrix_common.h>

using namespace std;

/**
* Author: Trek
*
* Commits:
* 22/12/14 Venio
* -Better output
* -Variable operand size
* -Fixed wrong results
* 04/01/2014 Venio
* -Fixed include error
* 10/01/2015 Venio
* -Rewrite everything!
**/

//Max size of the elements
#define MAX 10

unsigned int ax, ay, bx, by;

int main(){
	cout<<"Enter the dimensions of A separated by a space"<<endl;
	cin>>ax>>ay;

	cout<<"Enter the dimensions of B separated by a space"<<endl;
	cin>>bx>>by;

	if(ay!=bx){
		cout<<"Invalid matrix size!"<<endl;
		return 1;
	}
    
	double** a=new double*[ay];
	for(int i=0;i<ay;i++)
		a[i]=new double[ax];
	
	double** b=new double*[by];
	for(int i=0;i<by;i++)
		b[i]=new double[bx];
	
	double** c=new double*[ay];
	for(int i=0;i<ay;i++)
		c[i]=new double[bx];
	
	init_rand_matrix(a, ax, ay, MAX);
	init_rand_matrix(b, bx, by, MAX);
    
    	for(int i=0;i<by;i++){
        	for(int j=0;j<ax;j++){
			c[i][j]=0;
            		for(int index=0;index<bx;index++){
                		c[i][j]+=a[index][i]*b[j][index];
            		}
        	}
    	}

	print_matrix("A",	a, ax, ay);
	print_matrix("B",	b, bx, by);
	print_matrix("C=A*B",	c, ax, by);
    
    return 0;    
}
