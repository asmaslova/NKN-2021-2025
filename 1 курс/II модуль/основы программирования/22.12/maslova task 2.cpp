//Maslova Anastasia, RUDN, NKNbd-01-21, 22.12.2021 
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <math.h> 
using namespace std; 
//39.	Дана матрица размера   (M – четное число). Поменять местами верхнюю и нижнюю половины матрицы.
int main(){
    const int LIM=30;
    int i,i2,i1,j,n,m,a[LIM][LIM],a1[LIM][LIM],a2[LIM][LIM]; 
    cout<<"The program swaps the upper and the lower halves of the matrix. "<<endl;
    do{
        cout<<"Enter the amount of lines: ";
        cin>>n;
    }while(n<=0 || n>LIM || n%2!=0);
    do{
        cout<<"Enter the amount of columns: ";
        cin>>m;
    }while(m<=0 || m>LIM);
    for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cout<<"Enter the element "<<i+1<<" "<<j+1<<": ";
      cin>>a[i][j];
    }}
    
    cout<<"Matrix before swap: "<<endl;
    for (i=0; i<n; i++){
    for (j=0; j<m; j++)
        cout<<a[i][j]<<"\t";
        cout<<endl; 
    }
    
    i2=0;i1=0;i=0;j=0;
    int d=n/2;
    do{
        do{
        a1[i1][j]=a[i][j]; //upper half
        j++;
        }while(j<m);
        i++;
        i1++;
        j=0;
    }while(i<d);
    do{
        do{
        a2[i2][j]=a[i][j]; //lower half
        j++;
        }while(j<m);
        i++;
        i2++;
        j=0;
    }while(i<n);
    
    i=0;i1=0;i2=0;j=0;
    
    do{
        do{
            a[i][j]=a2[i2][j];
            j++;
        }while(j<m);
        i2++;
        i++;
        j=0;
    }while(i<(n/2));
    do{
        do{
            a[i][j]=a1[i1][j];
            j++;
        }while(j<m);
        i1++;
        i++;
        j=0;
    }while(i<n);
    
    cout<<"Matrix after swap: "<<endl;
    for (i=0; i<n; i++){
    for (j=0; j<m; j++)
        cout<<a[i][j]<<"\t";
        cout<<endl; }
    
}