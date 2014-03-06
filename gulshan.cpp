#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
        unsigned long long n,k;
 
        cin>>t;
 
        while(t--)
        {
                cin>>n>>k;
 
                if(k==0)
                cout<<"0 "<<n << "\n";          
        
                else
                cout<<n/k<<" "<<n%k << "\n";
        
        }
 
        return 0;
}