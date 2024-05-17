#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;


int main(){
	int n;
	int count=0;
	Matrix *mx_arr;
	
bool flag=false;
	while(!flag)
	{
    cout<<"Enter the number of the action you want to perform: "<<endl;
    cout<<"0. Quit the programm"<<endl<<"1. Create a matrix"<<endl<<"2. Sum the matrices"<<endl<<"3. Subtract the matrices"<<endl<<
    "4. Assign other values to the matrix"<<endl<<"5. Perform the unary minus operation"<<endl<<"6. Multiply two matrices"<<endl<<
    "7. Multiply a matrix by a number"<<endl<<"8. Multiply a matrix by a vector"<<endl<<"9. Display a certain matrix"<<endl<<
    "10. Show all the matrices"<<endl;
	cin >> n;
	cout << "\n";
	
	switch(n)
	{
	case 0:
        flag =true;
        break;
	
	case 1:
	{
        cout<< "Enter the amount of matrix lines:\n";
        int n;
        cin >> n;
        cout<< "Enter the amount of matrix columns:\n";
        int m;
        cin >> m;
        Matrix mx(n,m);
    	cout<<"Enter the matrix content line by line\n";
    	mx.scan();
	
        count++;
        Matrix *tmp = new Matrix[count];
        tmp[count-1] = mx;
        for (int i = 0; i < count-1; i++) 
        {
        	tmp[i] = mx_arr[i];
    	}
    	mx_arr = tmp;
        break;
	}
	
	case 2:
	{
	   int ind1,ind2;
	   cout << "Enter the id of the first matrix: \n";
	   cin >> ind1;
	   cout << "Enter the id of the second matrix:\n";
	   cin >> ind2;
	   if(ind1>count || ind2>count)
       {
	       cout << "No matrix with this id\n";
	   }
       else
	   {
	       Matrix res = mx_arr[ind1-1]+mx_arr[ind2-1];
	       cout << "Sum equals: \n";
	       res.print();
	   }
	   break;
	}
	
	case 3:
	{
	   int ind1,ind2;
	   cout << "Enter the id of the first matrix: \n";
	   cin >> ind1;
	   cout << "Enter the id of the second matrix:\n";
	   cin >> ind2;
	   if(ind1>count || ind2>count)
       {
	       cout << "No matrix with this id\n";
	   }
       else
	   {
	   Matrix res = mx_arr[ind1-1]+mx_arr[ind2-1];
	   cout << "Subtraction equals:\n";
	   res.print();
	   }
	   break;
	}
	

	case 4:
	{
	   int index;
	   cout << "Enter the id of the matrix you want to reassign: \n";
	   cin >> index;
	   if(index>count)
       {
	       cout << "No matrix with this id\n";
	   }
	   else
	   {
	       cout<< "Enter the amount of matrix lines: \n";
	       int n;
	       cin >> n;
           cout<< "Enter the amount of matrix columns: \n";
           int m;
           cin >> m;
           Matrix mx(n,m);
           cout<<"Enter the matrix content line by line\n";
           mx.scan();
           mx_arr[index-1] = mx;
	   }
	   break;
	}
	
	case 5:
	{
	   int index;
	   cout << "Enter the id of the matrix:\n";
	   cin >> index;
	   if(index>count){
	       cout << "No matrix with this id\n";
	   }
	   else
       {
        	mx_arr[index-1] = -mx_arr[index-1];
	   }
	   break;
	}
	
	case 6:
	{
	   int ind1,ind2;
	   cout << "Enter the id of the first matrix: \n";
	   cin >> ind1;
	   cout << "Enter the id of the second matrix: \n";
	   cin >> ind2;
	   if(ind1>count || ind2>count)
       {
	       cout << "No matrix with this id\n";
	   }
	   else{
	       cout << "Multiplication equals:\n";
	       (mx_arr[ind1-1]*mx_arr[ind2-1]).print();
	   }
	   break;
	   }
	 
	case 7:
    {
	   int ind, num;
	   cout << "Enter the id of the matrix: \n";
	   cin >> ind;
	   cout << "Enter the number to multiply matrix by: \n";
	   cin >> num;
	   if(ind>count)
       {
	       cout << "No matrix with this id\n";
	   }
	   else
       {
	       cout << "Multiplication equals: \n";
	       (mx_arr[ind-1]*num ).print();
	   }
	   break;
	}
	
	case 8:
	{
	   int ind;
	   Vector vect;
	   cout << "Enter the id of the matrix\n";
	   cin >> ind;
	   int len;
       cout<< "Enter the lenght of the vector: \n";
	   cin >> len;
	   float* vec = new float[len];
	   cout << "Enter the vector:\n";
	   for(int i=0; i<len;i++){
		cin >> vec[i];
	   }
	   vect.set(len, vec);
	   if(ind>count)
       {
	       cout << "No matrices with this id\n";
	   }
	   else
       {
	       cout << "Multiplication equals: \n";
	       (mx_arr[ind-1]*vect).print();
	   }
	   break;
	}
	
	case 9:
	{
	   if(count == 0)
       {
	       cout << "No matrices\n";
	   }
	   else
	   {
	       int index;
	       cout << "Enter the id number of the vector\n";
	       cin >> index;	
	       mx_arr[index-1].print();
	   }
	   break;
	}
	
	case 10:
	{
	   int num = 1;
	   if(count == 0)
       {
	       cout << "No matrices\n";
	   }
	   else
       {
	   for(int i = 0; i < count;i++){
		  cout << num << endl;
		  mx_arr[i].print();
		  num++;
        }
	   }
	break;
	}	
	}
	}
	
	return 0;
}
