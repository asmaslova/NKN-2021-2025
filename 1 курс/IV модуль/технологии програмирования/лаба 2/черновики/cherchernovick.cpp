#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class vect
{
	int dim; // razmernost'
	double *V; // massiv 
    double *asum, *asub, *aMulNum;
	
	public:
		int num;
		static int count;
		
		/*vect(int d, double *x);
		vect(int d);
		vect(vect &b); // copy*/
		vect(){} //constructor
		
		~vect(){} //destructor
		
		void set(int d, double *x)
		{
			dim=d;
			this->V=x;
		}
		
		void print()
		{
			cout << "(";
			for (int i = 0; i < dim; i++)
			{
				if (i == dim-1) cout<<this->V[i];
				else if(i < dim) cout<<this->V[i] << ";";
			}
			cout << ")";
		}
		
		vect& operator=(const vect &r); 
		vect& operator+(const vect& r); 
		friend vect& operator-(vect &l, vect &r); 
		vect& operator-();
		double operator*(vect &r); 
		friend vect& operator*(double k, vect& r);
};	


vect& vect::operator+(const vect& r) //сложение векторов
{
	for(int i=0; i<r.dim; i++)
	{
		this->asum[i]=this->V[i]+r.V[i];
	}
	return *this;	
}

vect& vect::operator=(const vect &r) //присваивание
{
	for(int i=0; i < r.dim; i++)
	{
		this->V[i]=r.V[i];
	}
	return *this; 
} 

vect& operator-(vect& l, vect& r) //вычитание векторов
{
	for (int i = 0; i < l.dim; i++)
	{
		this->asub[i]=l.V[i]-r.V[i];
	}
	return l;
}

vect& vect::operator-() // противоположный вектор
{
	for (int i = 0; i < this->dim; i++)
	{
		this->V[i]*=-1;
	}
	return *this;
}

double vect::operator*(vect &r) //скалярное умножение векторов
{
	double num1=0;
	for (int i = 0; i < this->dim; i++)
	{
		num1+=this->V[i]*r.V[i];
	}
	return num1;
}

vect& operator*(double k, vect& r) //умножение вектора на число
{
	for (int i = 0; i < r.dim; i++)
	{
		aMulNum[i]=r.V[i]*k;
	}
	return r;
}


int main()
{	
	int b;
    double asum[b], asub[b], aMulNum[b];
    vect sum, sub, MulNum;
    sum.set(b,asum);
    sub.set(b,asub);
    MulNum.set(b,aMulNum);
    cout<<"Enter the dimension of two vectors: ";
    cin>>b;
    double f[b];
    double s[b];
    cout<<"Enter the coordinates of the first vector: ";
    for (int i=0; i<b; i++){
        cin >> f[i];
    }
    cout<<"Enter the coordinated of the second vector: ";
    for (int i=0; i<b; i++){
        cin >> s[i];
    }
	vect first;
	first.set(b, f);
	
	vect second;
	second.set(b, s);
    
    cout<<"First vector: ";
    first.print();
    cout<<endl;
    
    cout<<"Second vector: ";
    second.print();
    cout<<endl;
	
    sum=first+second;
    cout<<"The sum of vectors: ";
    sum.print();
    cout<<endl;
	
    sub=first-second;
    cout<<"The subtraction of two vectors (first-second): ";
    sub.print();
    cout<<endl;
	
	MulNum = 3*first;
    cout<<"The multyplying a number 3 by the first vector: ";
    MulNum.print();
    cout<<endl;
    
    

	-first;
	first.print();

	return 0;
}