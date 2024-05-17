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

Vector& Vector::operator+(const Vector& r) //slozhenie vectorov
{ 
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


int main()
{	
    int b;
    float mul;
    cout<<"Enter the dimension of two vectors: ";
    cin>>b;
    float f[b];
    float s[b];
    float sum1[b], sub1[b], MulNum1[b];
    cout<<"Enter the coordinates of the first vector: ";
    for (int i=0; i<b; i++){
        cin >> f[i];
    }
    cout<<"Enter the coordinated of the second vector: ";
    for (int i=0; i<b; i++){
        cin >> s[i];
    }
    for (int i=0; i<b; i++){
        sum1[i] = 0;
    }
    for (int i=0; i<b; i++){
        sub1[i] = 0;
    }
    for (int i=0; i<b; i++){
        MulNum1[i] = 0;
    }
	Vector first;
	first.set(b, f);
	
	Vector second;
	second.set(b, s);
    
    Vector sum;
    sum.set(b,sum1);
    
    Vector sub;
    sub.set(b,sub1);
    
    Vector MulNum;
    MulNum.set(b,MulNum1);
    
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
    first=sum-second;
	
    sub=first-second;
    cout<<"The subtraction of two vectors (first-second): ";
    sub.print();
    first=sub+second;
    cout<<endl;
    
	mul=first*second;
	cout<<"Scalar multiplication of vectors: "<<mul<<endl;

	-first;
    cout<<"The vector opposite to the first: ";
	first.print();
    cout<<endl;
    -first;
	MulNum=3*first;
    cout<<"The multiplying a number 3 by the first vector: ";
    MulNum.print();
    cout<<endl;
	


	return 0;
}