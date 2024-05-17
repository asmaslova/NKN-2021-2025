//Maslova Anastasia, RUDN, NKNbd-01-21, 22.12.2021 
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <math.h> 
using namespace std; 
//#14 14.	Дана матрица размера MxN. Найти номер ее столбца с наименьшим произведением элементов и вывести данный номер, а также значение наименьшего произведения.
int main(){
    const int LIM=30;
    int min,S,S1,c,i,j,n,m,a[LIM][LIM]; 
    cout<<"The program outputs the number of the column of the matrix with the smallest multiplication and the result of this multiplication. "<<endl;
    do{
        cout<<"Enter the amount of lines: ";
        cin>>n;
    }while(n<=0 || n>LIM);
    do{
        cout<<"Enter the amount of columns: ";
        cin>>m;
    }while(m<=0 || m>LIM);
    for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cout<<"Enter the element "<<i+1<<" "<<j+1<<": ";
      cin>>a[i][j];
    }}
    cout<<"Matrix: "<<endl;
    for (i=0; i<n; i++){
    for (j=0; j<m; j++)
        cout<<a[i][j]<<"\t";
        cout<<endl; 
    }
    i=0;
    S=1;
    S1=1;
    min=0;
    for(j=0;j<m;j++){
            S=S*(a[i][j]);
        }
    i++;
    for(j=0;j<m;j++){
        S1=S1*(a[i][j]);
    }
    if (S<S1){
        min=S;
        c=i+(-1);
    }
    else{
        min=S1;
        c=i;
    };
    do{
        for(j=0;j<m;j++){
            S=S*(a[i][j]);
        }
        i++;
        for(j=0;j<m;j++){
            S1=S1*(a[i][j]);
        }
        if (S<S1){
            if (S<min){
                min=S;
                c=i+(-1);
            }else (min=min);
        }else{
            if (S1<min){
                min=S1;
                c=i;
            }else (min=min);}
        i++;
    }while(i!=n);
    
    cout<<"The smallest multiplication: "<<min<<endl;
    cout<<"The line: "<<c+1;
}
