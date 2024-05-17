#include <iostream>
#include <string>
#include "stdio.h"
#include "vector.h"

using namespace std;

class Matrix
{
public:
	friend class Vector;
	static int count; //matrix counter
	Matrix& operator = (const Matrix &r);
	Matrix operator + (Matrix &r);
	Matrix operator - (Matrix &r);
	Matrix operator - ();
	Matrix operator * (int k);
	Matrix operator * (Matrix &r);
	Matrix operator * (Vector &r);
	
    ~Matrix() 
	{
		delete[] matrix; //destructor
	}
	
	Matrix(int N=1, int M=1) //constructor
	{ 
	     n = N;
	     m = M;
	     matrix = new int *[n];
	      
	     for (int i = 0; i < n; ++ i)
		 {
			matrix[i] = new int[m];
		 for (int j = 0; j < m; ++ j)
		    matrix[i][j] = 0;
	     }
	}
	   
	   int* operator [] (int index) //calling by ID
	   {
	      return getRow (index);
	   }

	   int* getRow (int index) //matrix row
	   {
	      if (index >= 0 && index < n)
		 return matrix[index];
	      return 0;
	   }
	   
	   int* getColumn (int index) //matrix column
	   {
			if (index < 0 || index >= m)
			return 0;
			int * c = new int [n];
			for (int i = 0; i < n; ++ i)
			c[i] = matrix[i][index];
			return c;
	   }
	
	void scan() //reading a matrix from terminal
	{
   		Matrix matrix = Matrix (this->n, this->m);
   		for (int i = 0; i < n; ++ i)
		{
     		for (int j = 0; j < m; ++ j)
			{
        		cin >> this->matrix[i][j];
        	}
        }
   	
	}
	
	void print() //printing the matrix
	{
   	for (int i = 0; i < this->n; ++ i)
   	{
      	for (int j = 0; j < this->m; ++ j)
		{
        	cout << this->matrix[i][j]<< " ";
        }
        cout << endl;

  	}
  	
	}

private:
	int m, n; //rows and column amount
	int capacity;
	int **matrix;
	
};

Matrix &Matrix::operator=(const Matrix& r) // equality operator
      {  
        if (this != &r) 
        { 
           for ( int i = 0; i < this->n; i++ )
            {
                delete []matrix[i];
            }
            delete []matrix;
            this->n = r.n;
            this->m = r.m;

            matrix = new int*[n];
            for ( int i = 0; i < this->n; i++ )
            {
                matrix[i] = new int[this->m];
            }
            for (int i= 0; i < r.n; ++i) {
            for (int j = 0; j < r.m; ++j) {
               matrix[i][j] = r.matrix[i][j]; 
            }
            }
        }
   
       return *this;
       
       }
       
       


Matrix Matrix::operator + (Matrix &r)
{  
   if (r.n != this->n || r.m != this->m){
      cout<< "Different matrix size";
      exit(1);
   }
   Matrix res = Matrix (r.n, r.m);
   for (int i = 0; i < r.n; ++ i){
      for (int j = 0; j < r.m; ++ j){
         res[i][j] = r.matrix[i][j] + this->matrix[i][j];
         }
   
   }
   return res;
}

Matrix Matrix::operator - (Matrix &r)
{  
   if (r.n != this->n || r.m != this->m){
      cout<< "Different matrix size";
      exit(1);
   }
   Matrix res = Matrix (r.n, r.m);
   for (int i = 0; i < r.n; ++ i){
      for (int j = 0; j < r.m; ++ j){
         res[i][j] = this->matrix[i][j] - r.matrix[i][j];
   }
   }
   return res;
}

Matrix Matrix::operator - ()
{ Matrix res = Matrix (this->n, this->m);
  for(int i = 0; i < this->n; i++){
  	for(int j = 0; j < this->m; j++){
    		res.matrix[i][j] = -(this->matrix[i][j]);
  }
  }
  return res;
}



Matrix Matrix::operator * (int k){
	Matrix res = Matrix (this->n, this->m);
	for (int i = 0; i < this->n; ++i){
     	 	for (int j = 0; j < this->m; ++j){
         		res[i][j] = this->matrix[i][j] * k;
		}
	}
	return res;
}

Matrix Matrix::operator * (Matrix &r){
	if (this->m != r.n){
	     exit(1);
	}
	Matrix res = Matrix (this->n, r.m);
	for (int i = 0; i < this->n; ++ i){
	    for (int j = 0; j < r.m; ++ j){
			for (int k = 0; k < this->m; ++ k){
		    res[i][j] += this->matrix[i][k] * r.matrix[k][j];
			}
		}
	}
	   return res;

}


Matrix Matrix::operator * (Vector &r){
	Matrix res = Matrix(this->n, 1);
	if(r.dim!=this->m){
	cout << "Impossible to multiply";
	    exit(1);
	}
	else{
	for (int i = 0; i < this->n; ++ i){
		for (int j = 0; j < this->m; ++ j){
		    	res[i][0] += this->matrix[i][j] * r.V[j];
			}
		}
	}
	return res;
	
}

























