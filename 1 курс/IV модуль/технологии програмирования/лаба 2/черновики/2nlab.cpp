#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Vector
{
	private:
    int dim; // razmernost'
	double *V; // massiv 
	
	public:
		int num;
		static int count;

		Vector(){} //constructor
		
		~Vector(){} //destructor
		
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
		
		Vector& operator=(const Vector &r);
		Vector& operator+(const Vector& r); 
		friend Vector& operator-(Vector &l, Vector &r); 
		Vector& operator-();
		double operator*(Vector &r); 
		friend Vector& operator*(double k, Vector& r);
		double operator[](int i);
		
};	

Vector& Vector::operator+(const Vector& r) //сложение векторов
{
	for(int i=0; i<r.dim; i++)
	{
		this->V[i]=this->V[i]+r.V[i];
	}
	return *this;	
}

Vector& Vector::operator=(const Vector &r) //присваивание вектору вектора
{
	for(int i=0; i < r.dim; i++)
	{
		this->V[i]=r.V[i];
	}
	return *this; 
} 

Vector& operator-(Vector& l, Vector& r) //вычитание векторов
{
	for (int i = 0; i < l.dim; i++)
	{
		l.V[i]=l.V[i]-r.V[i];
	}
	return l;
}

Vector& Vector::operator-() // получение противоположного по знаку вектора
{
	for (int i = 0; i < this->dim; i++)
	{
		this->V[i]*=-1;
	}
	return *this;
}

double Vector::operator*(Vector &r) //скалярное произведение векторов
{
	double num1=0;
	for (int i = 0; i < this->dim; i++)
	{
		num1+=this->V[i]*r.V[i];
	}
	return num1;
}

Vector& operator*(double k, Vector& r) //произведение вектора на число
{
	for (int i = 0; i < r.dim; i++)
	{
		r.V[i]=r.V[i]*k;
	}
	return r;
}

double Vector::operator[](int i) //получение нужно числа из вектора по индексу
{
	return this->V[i];
}



int main()
{	
	double f[3]={1, 4, 3};
	Vector first;
	first.set(3, f);
	
	Vector second;
	double s[3]={1, 2, 3};
	second.set(3, s);
	
	first+second;
	first.print();
	second.print();
	
	/*first=first-second; 
	first.print();
	
	cout << first*second;
	first.print();

	3*first;
	first.print();

	cout << first[0];

	-first;
	first.print();*/

	return 0;
}