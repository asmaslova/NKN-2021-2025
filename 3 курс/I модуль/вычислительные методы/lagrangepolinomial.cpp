#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
/*Lab 1. Variant 5
f(x)=sin(cos(x^2-x-1)); 0<=x<=pi*/

double lagrangePolinomial(double *x, double *y, int n, double xx){
    double l;
    double q;
    l = 0.0;
    for(int i=0; i<=n; i++){
        q = 1.0;
        for(int j=0;j<=n;j++){
            if(j!=i) q = q*(xx-x[j])/(x[i]-x[j]);
        }
        l = l+y[i]*q;
    }
    return l;
}

int main(){
    
    const double pi = acos(-1.0);
    double xx;
    
    
    
    int n=10;
    double x[n+1] = {};
    x[0]=0;
    
    for (int i=1;i<=n;i++){
        x[i]=x[i-1]+pi/10;
    }
    
    
    double y[n+1] = {};
    
    for (int i=0;i<=n;i++){
        y[i] = sin(cos((pow(x[i],2))-x[i]-1));
    }
    
    /*{0, pi/10, 2*pi/10, 3*pi/10, 4*pi/10, 5*pi/10, 
                    6*pi/10, 7*pi/10, 8*pi/10, 9*pi/10, pi};*/
    
    
    /*0.01744974862109, 0.340926890593, 0.32489864471181, 0.47407382442516,
                    0.702669229190831, 0.8385735000885235, 0.7068243955956861, -0.06609841536829462,
                    -0.8095079887880354, -0.4958355256687336, 0.7511543157497503
                    */
    
    double uwu = lagrangePolinomial(x, y, n, xx);
    
    std::cout<<"Task 3: "<<uwu<<"\n";
    
    int m = 3*n + 1;
    double x1[m] = {};
    x1[0]=0;
    for (int i=1;i<m;i++){
        x1[i]=x1[i-1]+pi/30;
    }
    /*for (int i=0;i<m+1;i++){
        std::cout<<x1[i]<<" ";
    }
    */
    double y1[m] = {};
    double l1[m] = {};
    double accuracy[m] = {};
    for (int i=0;i<m;i++){
        y1[i]=sin(cos(pow(x1[i],2)-x1[i]-1));
    }
    
    for (int i=0;i<m;i++){
        l1[i] = lagrangePolinomial(x, y, n, x1[i]);
        accuracy[i] = l1[i]-y1[i];
    }
    
    std::cout<<"Task 5: \n";
    for (int i=0;i<m;i++){
        std::cout<<x1[i]<<"   "<<y1[i]<<"   "<<l1[i]<<"   "<<accuracy[i]<<"\n";
    }
    
    
    
    


}