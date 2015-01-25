#include <iostream>
#include <cstdlib>

using namespace std;

/*
 *Author: Trek
 */

 //inizio main
 
 #define MAX 10
 
int main(){
    int m, n, p, q;
    
    cout<<"insert first matrix dimensions : \nI suggest not to insert number greater than 3*3, you'll see why if you try"<<endl;
    cin>>m>>n;
    cout<<"insert second matrix dimensions:"<<endl;
    cin>>p>>q;
    int A[m][n];
    int B[p][q];
    int C[m*p][n*q];
    srand(time(NULL));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j]=rand()%MAX;
        }
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            B[i][j]=rand()%MAX;
        }
    }
    
    for(int i=0;i<m*p;i++){
        for(int j=0;j<n*q;j++){
            C[i][j]=A[i/m][j/n]*B[i%p][j%q];
        }
    }
    cout<<"A| dimensions: "<<m<<" "<<n<<" :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nB| dimensions: "<<p<<" "<<q<<" :"<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cout<<B[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nC| dimensions: "<<m*p<<" "<<n*q<<" :"<<endl;
    for(int i=0;i<m*p;i++){
        for(int j=0;j<n*q;j++){
            cout<<C[i][j]<<"\t";
        }
        cout<<endl;
    }

    system("PAUSE");

}
//fine main

