//Maslova Anastasia, RUDN, NKNbd-01-21, 15.12.2021

#include <iostream> 
#include <math.h> 
using namespace std; 
int main()
{
    cout<<"The programm is for determining the number of ascending and descending intervals of an massive. The massive has 20 elements."<<endl;
    const int N = 20;
    int i, c; //i - счетчик элементов, d - флаг, c - счетчик промежутков
    int A[N];
    cout<<"Enter the elements of the massive: "<<endl;
    for (i=1; i<=N;){
    	cout<<"A["<<i<<"] = ";
    	cin>>A[i];
    	i++;
	}
	
	bool prev=false;
	if(A[1]>=A[0])
		prev=true;
	else prev=false;
	
	bool d = false;
	c = 0;
	i=1;
	do{
		if (A[i+1]>=A[i])
			d=true;
		else d=false;	
		if(prev!=d){
			c++;
			prev=d;
		}
		i++;
	}while(i<=(N+(-1)));
	cout<<"Amount of intervals: "<<c;
	return 0;
	
}