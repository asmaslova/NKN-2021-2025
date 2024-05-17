#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
using namespace std; 

//f(x)=x+sinx, [a,b] = [0,pi]
//f(x)=x*cos(2*x+1), [a,b] = [-1;1]

double f(double x){
    return x*cos(2*x+1);
}

double integralLeftRectangle(double a, double b, int n){
    
    double h = (b-a)/n;

    double pp = 0;
    
    for (int i=0;i<n;i++){
        pp += h*f(a+h*i);
        //cout<<"pp"<<" = "<<pp<<"\n";
    }
    return pp;
}

double integralRightRectangle(double a, double b, int n){

    double h = (b-a)/n;
    
    double pp = 0;
    
    for (int i=1;i<=n;i++){
        pp += h*f(a+h*i);
        //cout<<"pp"<<" = "<<pp<<"\n";
    }
    return pp;
}

double integralTrapezoid(double a, double b, int n){
    
    double h = (b-a)/n;
   
    double tt = 0;
    for (int i=0;i<n;i++){
        tt += 0.5*h*(f(a+i*h)+f(a+(i+1)*h));
    }
    return tt;
}

double integralSimpson(double a, double b, int n){
    if (n%2!=0) return NAN;
    double h = (b-a)/n;
    double ss = ((b-a)/(3*n))*(f(a)+f(b));
    double x[n+1];
    
    
    for (int i=0;i<=n;i++){
        x[i] = a+i*h;
    }
    
    for (int i=1;i<n;i++){
        if (i%2!=0){
            ss += ((b-a)/(3*n))*4*f(x[i]);
        }else ss += ((b-a)/(3*n))*2*f(x[i]);
    }
    
    return ss;
}

int main(){
    int n=16;
    double a = -1;
    double b = 1;
    double analytic = -0.732749188991160935944006109954653836419312277581430379881480331;
    //cout<<"n       Analitical solution    Left Rectangles Method    Right Rectangles Method     Trapezoid method   Simpson method\n";
    cout<<" "<<n<<"      "<<analytic<<"              "<<integralLeftRectangle(a,b,n)<<"                 "<<integralRightRectangle(a,b,n)<<"                   "<<integralTrapezoid(a,b,n)<<"           "<<integralSimpson(a,b,n)<<"\n";
    cout<<" "<<n*2<<"      "<<analytic<<"              "<<integralLeftRectangle(a,b,n*2)<<"                 "<<integralRightRectangle(a,b,n*2)<<"                   "<<integralTrapezoid(a,b,n*2)<<"          "<<integralSimpson(a,b,2*n)<<"\n";
    cout<<" "<<n*5<<"      "<<analytic<<"              "<<integralLeftRectangle(a,b,n*5)<<"                 "<<integralRightRectangle(a,b,n*5)<<"                   "<<integralTrapezoid(a,b,n*5)<<"          "<<integralSimpson(a,b,5*n)<<"\n";
    cout<<" "<<n*10<<"     "<<analytic<<"              "<<integralLeftRectangle(a,b,n*10)<<"                 "<<integralRightRectangle(a,b,n*10)<<"                   "<<integralTrapezoid(a,b,n*10)<<"          "<<integralSimpson(a,b,10*n)<<"\n";
    
    cout<<"\n\n";
    
    for (int i=1;i<=100000;i++){
        if(abs(analytic-integralLeftRectangle(a,b,i))<0.001) {n=i; break;}
        else continue;
    }
    cout<<" "<<n-2<<"      "<<analytic<<"              "<<integralLeftRectangle(a,b,n-2)<<"                 "<<abs(analytic-integralLeftRectangle(a,b,n-2))<<"\n";
    cout<<" "<<n-1<<"      "<<analytic<<"              "<<integralLeftRectangle(a,b,n-1)<<"                 "<<abs(analytic-integralLeftRectangle(a,b,n-1))<<"\n";
    cout<<"* "<<n<<"      "<<analytic<<"              "<<integralLeftRectangle(a,b,n)<<"                 "<<abs(analytic-integralLeftRectangle(a,b,n))<<"\n";
    cout<<" "<<n+1<<"      "<<analytic<<"              "<<integralLeftRectangle(a,b,n+1)<<"                 "<<abs(analytic-integralLeftRectangle(a,b,n+1))<<"\n";
    
    cout<<"\n\n";
    
    for (int i=1;i<=100000;i++){
        if(abs(analytic-integralRightRectangle(a,b,i))<0.001) {n=i; break;}
        else continue;
    }
    cout<<" "<<n-2<<"      "<<analytic<<"              "<<integralRightRectangle(a,b,n-2)<<"                 "<<abs(analytic-integralRightRectangle(a,b,n-2))<<"\n";
    cout<<" "<<n-1<<"      "<<analytic<<"              "<<integralRightRectangle(a,b,n-1)<<"                 "<<abs(analytic-integralRightRectangle(a,b,n-1))<<"\n";
    cout<<"* "<<n<<"      "<<analytic<<"              "<<integralRightRectangle(a,b,n)<<"                 "<<abs(analytic-integralRightRectangle(a,b,n))<<"\n";
    cout<<" "<<n+1<<"      "<<analytic<<"              "<<integralRightRectangle(a,b,n+1)<<"                 "<<abs(analytic-integralRightRectangle(a,b,n+1))<<"\n";
    //cout<<integralTrapezoid(0,M_PI,n*10 );
    
    cout<<"\n\n";
    
    for (int i=1;i<=100000;i++){
        if(abs(analytic-integralTrapezoid(a,b,i))<0.001) {n=i; break;}
        else continue;
    }
    cout<<" "<<n-2<<"      "<<analytic<<"              "<<integralTrapezoid(a,b,n-2)<<"                 "<<abs(analytic-integralTrapezoid(a,b,n-2))<<"\n";
    cout<<" "<<n-1<<"      "<<analytic<<"              "<<integralTrapezoid(a,b,n-1)<<"                 "<<abs(analytic-integralTrapezoid(a,b,n-1))<<"\n";
    cout<<"* "<<n<<"      "<<analytic<<"              "<<integralTrapezoid(a,b,n)<<"                 "<<abs(analytic-integralTrapezoid(a,b,n))<<"\n";
    cout<<" "<<n+1<<"      "<<analytic<<"              "<<integralTrapezoid(a,b,n+1)<<"                 "<<abs(analytic-integralTrapezoid(a,b,n+1))<<"\n";
    
    cout<<"\n\n";
    
    for (int i=1;i<=100000;i++){
        if(abs(analytic-integralSimpson(a,b,i))<0.001) {n=i; break;}
        else continue;
    }
    cout<<" "<<n-4<<"      "<<analytic<<"              "<<integralSimpson(a,b,n-4)<<"                 "<<abs(analytic-integralSimpson(a,b,n-4))<<"\n";
    cout<<" "<<n-2<<"      "<<analytic<<"              "<<integralSimpson(a,b,n-2)<<"                 "<<abs(analytic-integralSimpson(a,b,n-2))<<"\n";
    cout<<"* "<<n<<"      "<<analytic<<"              "<<integralSimpson(a,b,n)<<"                 "<<abs(analytic-integralSimpson(a,b,n))<<"\n";
    cout<<" "<<n+2<<"      "<<analytic<<"              "<<integralSimpson(a,b,n+2)<<"                 "<<abs(analytic-integralSimpson(a,b,n+2))<<"\n";
    
}