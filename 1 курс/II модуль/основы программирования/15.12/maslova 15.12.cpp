//Maslova Anastasia, RUDN, NKNbd-01-21, 15.1s2.2021

#include <iostream>
using namespace std; 
int main()
{
    int d;
    const int N = 20;
    cout<<"The programm outputs numbers of an massive with an odd number in ascending order, and then with an even number in descending order. The massive has 20 elements."<<endl;
    int A[N];
    int i;
    cout<<"Enter the elements of the massive: "<<endl;
    for (i=1; i<=N;){
    	cout<<"A["<<i<<"] = ";
    	cin>>A[i];
    	i++;
	}
	cout<<"Output: "<<endl;
	for (i=1; i<=N;){
    	cout<<"A["<<i<<"] = "<<A[i]<<endl;
    	i=i+2;
	}
	d = N%2;
	switch (d){
	case(0): 
		{for (i=N; i>0;)
			{cout<<"A["<<i<<"] = "<<A[i]<<endl;
    		i=i+(-2);}
    		break;
		}
	default:
		{for (i=(N+(-1)); i>0;)
			{cout<<"A["<<i<<"] = "<<A[i]<<endl;
    		i=i+(-2);}
    		break;
		}	
	}
    //cout <<
    //cin >>
}
