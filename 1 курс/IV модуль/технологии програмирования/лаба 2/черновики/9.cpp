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
	
	public:
		int num;
		static int count;
		
		vect(int d, double *x);
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
		
		vect& operator=(const vect &r); //+
		vect& operator+(const vect& r); //+
		friend vect& operator-(vect &l, vect &r); //+
		vect& operator-();
		double operator*(vect &r); 
		friend vect& operator*(double k, vect& r);
		double operator[](int i);
		
};	

vect& vect::operator+(const vect& r) //сложение векторов
{
	for(int i=0; i<r.dim; i++)
	{
		this->V[i]=this->V[i]+r.V[i];
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
		l.V[i]=l.V[i]-r.V[i];
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
		r.V[i]=r.V[i]*k;
	}
	return r;
}




int main()
{	
	int b;
    cout<<"Enter the dimension of two vectors: ";
    cin>>b;
    double f[b];
    double s[b];
    cout<<"Enter the coordinates of the first vector: ";
    for (int i=0; i<b; i++)
    {
        cin >> f[i];
    }
    cout<<"Enter the coordinated of the second vector: ";
    for (int i=0; i<b; i++)
    {
        cin >> s[i];
    }
	
    vect first;
	first.set(b, f);
	
	vect second;
	second.set(b, s);
    
    cout<<"The sum of vectors: ";
    first+second;
	first.print();
	first=first-second;
	cout<<endl;
    
    cout<<"The subtraction of vectors: ";
	first=first-second; 
	first.print();
    cout<<endl;
    first=first+second;
	
	cout << first*second;
	first.print();

	3*first;
	first.print();

	-first;
	first.print();

	return 0;
}