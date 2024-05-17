#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iomanip>

using namespace std; 
//variant 5


int main() {

    double d, s;
    int n = 4;
    
    double *x = new double [n];
    
    double a[4][4] =  //calculate it
    {
    {8*M_PI, 1, 4, 2},
    {1, 9*M_PI, 3, 2},
    {4, 3, 7*M_PI, 3},
    {1, 4, 1, 8*M_PI}
    };
    
    double b[4] = {2, 7, 3, 3};
    
    double aa[4][4] =  //how it was
    {
    {8*M_PI, 1, 4, 2},
    {1, 9*M_PI, 3, 2},
    {4, 3, 7*M_PI, 3},
    {1, 4, 1, 8*M_PI}
    };
    
    double bb[4] = {2, 7, 3, 3};
    
    for (int k=0; k<n; k++){ //direct
        for (int j=k; j<n; j++){
            d = a[j][k] / a[k][k]; 
            for (int i=k; i<=n; i++){
                a[j][i] = a[j][i] - d * a[k][i]; 
            }
            b[j] = b[j] - d * b[k];
        }
    }
    
    for (int k=n-1; k<=0; k--){ //reverse
        d = 0;
        for (int j=k; j<n; j++){
            s = a[k][j] * x[j]; 
            d = d + s; 
        }
        x[k] = (b[k] - d) / a[k][k]; 
    }
    
    cout<<"Matrix A and vector b: \n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<aa[i][j]<<"  ";
        }
        cout<<bb[i]<<"\n";
    }
    
    cout<<"\n";
    
    cout<<"Upper triangular A and vector b: \n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<b[i]<<"\n";
    }
    
    /*double xx[] = {1,1,1,1};
    for(int i=3;i>-1;i--){
        double tmp = 0;
        for (int j=i+1;j<4;j++){
            tmp += matrix[i][j] * xx[j];
        }
        xx[i] = vector[i] - tmp;
        
    }*/
    
    cout<<"\n";
    
    cout<<"Solution vector: \n";
    for(int i=0;i<4;i++){
        cout<<x[i]<<"\n";
    }
    
    double ax[4];
    
    for(int i=0; i<4; i++){
        for(int j=0;j<4;j++){
            ax[i] += aa[i][j]*x[j];
        }
    }
    
    double epsilonRaw[4] = {};
    for(int i=0;i<4;i++){
        epsilonRaw[i] = ax[i] - bb[i];
    }
    
    double epsilon = 0;
    for (int i=0;i<4;i++){
        epsilon += pow(abs(epsilonRaw[i]),2);
    }
    
    cout<<"Epsilon: "<<epsilon;

}