#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>


double newtonPolinomial(double *x, double *y, int n, double xx){
    double aa[n+1] = {};
    aa[0]=0;
    double sum = 0;
    double omega = 1;
    for (int i=n;i>=0;i--){
        for(int k=0;k<=i;k++){
            for(int j=0;j<=i;j++){
                if(k!=j) {
                    omega*=(x[k]-x[j]);
                }
            }
            aa[i] = aa[i] +(y[k]/omega);
            omega=1;
        }
        sum = sum *(xx-x[i]);
        sum = sum+aa[i];
    }
    return sum;
    
}

int main(){
    //const double pi = acos(-1.0);
    //std::cout<<M_PI;
    double xx;
    
    int n=10;
    double x[n+1] = {};
    x[0]=0;
    std::cout<<"X: \n";
    for (int i=1;i<=n;i++){
        x[i]=x[i-1]+M_PI/n;
    }
    for (int i=0;i<=n;i++){
        std::cout<<x[i]<<"\n";
    }
    std::cout<<"Y: \n";
    double y[n+1] = {};
    for (int i=0;i<=n;i++){
        y[i] = sin(cos((x[i]*x[i])-x[i]-1));
        std::cout<<y[i]<<"\n";
    }
    
    //std::cout<<"UWU \n";
    
    double uwu = newtonPolinomial(x,y,n,xx);
    
    std::cout<<"Newton Polinomial "<<uwu<<"\n";
    
    int m = 3*n;
    
    double x1[m+1] = {};
    x1[0]=0;
    for (int i=1;i<=m;i++){
        x1[i]=x1[i-1]+M_PI/m;
    }
    
    double y1[m+1] = {};
    for (int i=0;i<=m;i++){
        y1[i] = sin(cos((x1[i]*x1[i])-x1[i]-1));
        
    }
    
    double newton[m+1] = {};
    for (int i=0;i<=m;i++){
        newton[i] = newtonPolinomial(x,y,n,x1[i]);
    }
    
    double accuracy[m+1] = {};
    for(int i=0;i<=m;i++){
        accuracy[i] = newton[i]-y1[i];        
    }
    
    for(int i=0;i<=m;i++){
        std::cout<<x1[i]<<"   "<<y1[i]<<"   "<<newton[i]<<"   "<<accuracy[i]<<"\n";
    }
    
    
    
    
    
}