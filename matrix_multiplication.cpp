#include <cstdlib>
#include <iostream>

using namespace std;

/**
* Author: Trek
**/


int main(){
    
    int m1=4;
    int n1=2;
    int m2=2;
    int n2=3;
    int size=10;
    
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
            for(int index=0;index<n1;index++){
                c[i][j]=a[i][index]*b[index][j];
            }
        }
    }
    
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
                cout<<"c["<<i+1<<"]["<<j+1<<"] ("<<c[i][j]<<")"<<endl;
        }
    }
    system("PAUSE");
    return 0;    
}
