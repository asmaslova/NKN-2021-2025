#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Vector
{
	int dim; // razmernost'
	float *V; // massiv 
    
    friend class Matrix;
    
	public:
		int num;
		static int count;
		
		Vector(){} //constructor
		
		~Vector(){} //destructor
		
		void set(int d, float *x)
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
		
		Vector& operator=(const Vector &r); //+
		Vector& operator+(const Vector& r); //+
		friend Vector& operator-(Vector &l, Vector &r); //+
		Vector& operator-();
		double operator*(Vector &r); 
		friend Vector& operator*(float k, Vector& r);
		
};	

Vector& Vector::operator+(const Vector& r){ //slozhenie vectorov
    for(int i=0; i<r.dim; i++)
	{
		this->V[i]=this->V[i]+r.V[i];
	}
	return *this;	
}

Vector& Vector::operator=(const Vector &r) //prisvaivanie
{
	for(int i=0; i < r.dim; i++)
	{
		this->V[i]=r.V[i];
	}
	return *this; 
} 

Vector& operator-(Vector& l, Vector& r) //vychitanie vectorov
{
	for (int i = 0; i < l.dim; i++)
	{
		l.V[i]=l.V[i]-r.V[i];
	}
	return l;
}

Vector& Vector::operator-() //protivopolozhniy vector
{
	for (int i = 0; i < this->dim; i++)
	{
		this->V[i]*=-1;
	}
	return *this;
}

double Vector::operator*(Vector &r) //umnozhenie vectorov
{
	double num1=0;
	for (int i = 0; i < this->dim; i++)
	{
		num1+=this->V[i]*r.V[i];
	}
	return num1;
}

Vector& operator*(float k, Vector& r) //umnozhenie vectora na chislo
{
	for (int i = 0; i < r.dim; i++)
	{
		r.V[i]=r.V[i]*k;
	}
	return r;
}
