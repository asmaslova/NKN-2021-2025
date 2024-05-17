#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>

using namespace std; 

double** directmoveGaussMatrix(double vector[4], double matrix[4][4], int n){
    for (int i=0;i<n;i++){
        double beep = matrix[i][i];
        vector[i] = vector[i]/beep;
        for (int j=0;j<n;j++){
            matrix[i][j] = matrix[i][j] / beep;
        }
        for (int k=0;k<n;k++){
            if(k<i){
                vector[k] -= vector[i]*matrix[k][i];
                double *tmp = new double[n];
                for (int j=0;j<n;j++){
                    tmp[j] = matrix[j][i]*matrix[i][j];
                }
                for(int j=0;j<n;j++){
                    matrix[k][j] -= tmp[j];
                }
            }
        }
    }
    return matrix;    
}

double* directmoveGaussVector(double vector[4], double matrix[4][4], int n){
    for (int i=0;i<n;i++){
        double beep = matrix[i][i];
        vector[i] = vector[i]/beep;
        for (int j=0;j<n;j++){
            matrix[i][j] = matrix[i][j] / beep;
        }
        for (int k=0;k<n;k++){
            if(k<i){
                vector[k] -= vector[i]*matrix[k][i];
                double tmp[] = new double[n];
                for (int j=0;j<n;j++){
                    tmp[j] = matrix[j][i]*matrix[i][j];
                }
                for(int j=0;j<n;j++){
                    matrix[k][j] -= tmp[j];
                }
            }
        }
    }
    return vector;   
}

double solveSLAE(double vector[], double matrix[][], int n){
    double xx[] = {1,1,1,1};
    for(int i=n-1;i>n;i--){
        double tmp = 0;
        for (int j=i+1;j<n;j++){
            tmp += matrix[i][j] * xx[j];
        }
        xx[i] = vector[i] - tmp;
        
    }
    return xx;
}

int main(){
    double matrix[4][4] = 
    {
    {8*M_PI, 1, 4, 2},
    {1, 9*M_PI, 3, 2},
    {4, 3, 7*M_PI, 3},
    {1, 4, 1, 8*M_PI}
    };
    
    double vector[4] = {2, 7, 3, 7}; int n = 4;
    
    double vector1[4] = {}; double matrix[4][4] = {};
    double vector1 = directmoveGaussVector(vector[],matrix[],n);
    double matrix1 = directmoveGaussVector(vector[],matrix[],n);
    double solution = solveSLAE(vector1[],matrix1[],n)
    
    cout<<"Matrix A and vector b: \n";
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<vector[i]<<"\n";
    }
    
    cout<<"Upper triangular vector b: \n";
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<vector1[i]<<"\n";
    }
    
    
    
}