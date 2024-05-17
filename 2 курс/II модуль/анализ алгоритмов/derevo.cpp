#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    int n;    
    string answer;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        long long int p0=1; //p - chislitel, q - znamenatel, f - drob'
        long long int q0=1; 
        long long int p_left=0;
        long long int q_left=1;   
        long long int p_right=1;
        long long int q_right=0;  
        long long int p;
        long long int q; 
        if(line[0]=='L' || line[0]=='R'){
            for(int k=0; k<line.size(); k++){
                if(line[k]=='L'){
                    p_right=p0;
                    q_right=q0;
                    p0=p_right+p_left;
                    q0=q_right+q_left;
                }else{
                    p_left=p0;
                    q_left=q0;
                    p0=p_left+p_right;
                    q0=q_left+q_right;
                }
            }
            cout<<p0<<'/'<<q0<<endl;
        }
        else{
            p=stoi(line.substr(0, line.find("/"))); //nastroit'
            q=stoi(line.substr(line.find("/")+1));
            float f0=p0/q0;
            float f=p/q;
            while(f!=f0 || (p0!=p && q0!=q)){
                if(f<f0){
                    p_right=p0;
                    q_right=q0;
                    p0=p_right+p_left;
                    q0=q_right+q_left;
                    answer+='L';
                }else{
                    p_left=p0;
                    q_left=q0;
                    p0=p_left+p_right;
                    q0=q_left+q_right;
                    answer+='R';
                }
            }
            cout<<answer<<endl;
        }
    }

}
    
    
    
    
    
    
    
    
    
    
    
    