#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iomanip>

using namespace std; 
//variant 5

int main(){
    
    double matrixRaw[4][4] = 
    {
    {8*M_PI, 1, 4, 2},
    {1, 9*M_PI, 3, 2},
    {4, 3, 7*M_PI, 3},
    {1, 4, 1, 8*M_PI}
    };
    
    double vectorRaw[4] = {2, 7, 3, 3};
    
    double matrix[4][4] = 
    {
    {8*M_PI, 1, 4, 2},
    {1, 9*M_PI, 3, 2},
    {4, 3, 7*M_PI, 3},
    {1, 4, 1, 8*M_PI}
    };
    
    double vector[4] = {2, 7, 3, 3}; //регуляризация Тихонова
    
    cout<<"Matrix A and vector b: \n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<vector[i]<<"\n";
    }
   
   //
    for (int i=0;i<4;i++){ //stroke
        double temp = matrix[i][i];
        vector[i] = vector[i]/temp;
        for (int j=0;j<4;j++){
            matrix[i][j] = matrix[i][j] / temp;
        }
        for (int k=0;k<4;k++){ //
            if(k>i){
                vector[k] -= vector[i]*matrix[k][i];   
                double tmp[4] = {};
                for (int j=0;j<4;j++){
                    tmp[j] = matrix[k][i]*matrix[i][j];
                    //cout<<i<<"i  "<<k<<"k   "<<j<<"j   "<<tmp[j]<<"tmp  \n";
                }
                
                for(int j=0;j<4;j++){
                    matrix[k][j] -= tmp[j];
                }
            }
            //cout<<matrix[i][k]<<" ";
        }
      //cout<<"\n";        
    }
    
    cout<<"\n";
    
    cout<<"Upper triangular A and vector b: \n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<vector[i]<<"\n";
    }
    
    double xx[] = {1,1,1,1};
    for(int i=3;i>-1;i--){
        double tmp = 0;
        for (int j=i+1;j<4;j++){
            tmp += matrix[i][j] * xx[j];
        }
        xx[i] = vector[i] - tmp;
        
    }
    
    cout<<"\n";
    
    cout<<"Solution vector: \n";
    for(int i=0;i<4;i++){
        cout<<xx[i]<<"\n";
    }
    
    double ax[4];
    
    for(int i=0; i<4; i++){
        for(int j=0;j<4;j++){
            ax[i] += matrixRaw[i][j]*xx[j];
        }
    }
    
    double epsilonRaw[4] = {};
    for(int i=0;i<4;i++){
        epsilonRaw[i] = ax[i] - vectorRaw[i];
    }
    
    double epsilon = 0;
    for (int i=0;i<4;i++){
        epsilon += pow(abs(epsilonRaw[i]),2);
    }
    
    cout<<"Epsilon: "<<epsilon;

}




