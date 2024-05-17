#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>

using namespace std; 

double f(double x, double y){
    return 2*x*y;
}

double* eilerCauchy(double a, double b, int n, double y0){
    double *y = new double [n+1];
    y[0]=y0;
    
    double h = (b-a)/n;
    //cout<<h<<"h \n";
    
    double *x = new double [n+1];
    x[0] = a;
    for(int i=1;i<=n;i++){
        x[i] = x[0] + h*i;
        //cout << x[i] << "x \n";
    }
     
    for (int i=0;i<n;i++){
        y[i+1] = y[i]+h*f(x[i],y[i]);   
    }
       
    return y;
}

double* analyticalSolution(double *x, int n){
    double *yy = new double [n+1];
    for (int i=0;i<=n;i++){
        yy[i] = pow(M_E,x[i]*x[i]);
    }
    return yy;
}


int main(){

    double a = 0; double b = 1; int n = 32; double y0 = 1; 
    
    double h = (b-a)/n;
    
    double *x = new double [n+1];
    x[0] = a;
    for(int k=1;k<=n;k++){
        x[k] = x[0] + k*h;
        //cout<<x[k]<<"\n";
    }
    
    double* y = eilerCauchy(a, b, n, y0); 
    double* yy = analyticalSolution(x, n);
    double *accuracy = new double[n+1];
    //cout<<"uwu \n";
    
    for (int i=0;i<=n;i++){
        accuracy[i] = abs(y[i]-yy[i]);
    }
    
    for (int i=0;i<=n;i++){
        cout<<x[i]<<"      "<<y[i]<<"      "<<yy[i]<<"      "<<accuracy[i]<<"\n";
    }
    cout<<"\n \n";
    
    for (int i=2;i<=100000000;i++){
        //double aa = 0; double bb = 1; double yy0 = 1; 
    
        double hh = (b-a)/i;
    
        double *xx = new double [i+1];
        xx[0] = a;
        for(int k=1;k<=i;k++){
            xx[k] = xx[0] + k*hh;
        //cout<<x[k]<<"\n";
        }
    
        double* y1 = eilerCauchy(a, b, i, y0); 
        double* yy1 = analyticalSolution(xx, i);
        double *acc = new double[i+1];
        //cout<<"uwu \n";
    
        for (int j=0;j<=i;j++){
            acc[j] = abs(y1[j]-yy1[j]);
        }
        
        double a_max=0;
        for (int j=0; j<=i; j++){
            if (acc[j]>a_max) a_max=acc[j];  
            else continue;
        }
        
        if(a_max<0.01){
            cout<<i<<" max \n";
            break;
        } else continue;
        
        /*double *xx = new double [i+1];
        double hh = (b-a)/i;
        xx[0] = a;
        for(int k=1;k<=i;k++){
            xx[k] = xx[0] + k*hh;
            //cout<<x[k]<<"\n";
        }
        
        double* y1 = eilerCauchy(a,b,i,y0);
        double* yy1 = analyticalSolution(x,i);
        
        double *acc = new double[i+1];
        //bool have = true;
        for (int j=0;j<=i;j++){
            acc[j] = abs(y1[j]-yy1[j]);
        }
        
        double a_max=0;
        for (int j=0; j<=i; j++){
            if (acc[j]>a_max) {a_max=acc[j];}
            else continue;
        }
        if(a_max<0.01) {cout<<"min N = "<<i<<"\n"; break;}
        else continue;
        */
    }
}