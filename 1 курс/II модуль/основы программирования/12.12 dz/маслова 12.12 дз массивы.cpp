//Maslova Anastasia, RUDN, NKNbd-01-21, 13.12.21
#include <iostream> 
#include <math.h>
using namespace std; 
int main()
{
    int i = 0, s=0;
	int a[17];
	cout<<"Enter the elements of massive: \n";
    for ((i=0); (i<18);) {
		cout<<"A["<<i<<"]: ";
		cin>>a[i];
    	i++;
	}
	for ((i=0);(i<18);){
		if (a[i]%2==0){
			s=s+a[i];
			i++;
		}else i++;
	}
	cout<<s<<endl;
	i=0;
	do{
		if (a[i]%3==0) {
			a[i]=s;
			i++;
		}else i++;
	}while(i<18);
	
    for ((i=0); (i<18);) {
    	cout<<"A["<<i<<"]: "<<a[i]<<endl;
    	i++;
    	
	}
}
	

