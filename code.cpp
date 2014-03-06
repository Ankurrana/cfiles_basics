#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
using namespace std;
#include <climits>
 
typedef unsigned long long uint64;
#define get getchar_unlocked
#define repeat(n) for (int i = (1); i <= n; i++)
#define ZERO(v) memset((v), 0, sizeof (v))
#define ALL(x) (x).begin(), (x).end()
 

inline long long int scan2(){
	long long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


long long int a[20000] = {0};

long long int f(long long int n,long long int k,long long int ans,string op){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			
			if(op.compare("OR") == 0)
				ans = ans | a[j];
			else if(op.compare("AND") == 0)
				ans = ans & a[j];
			else if(op.compare("XOR") == 0)
				ans = ans^a[j];
		}

		
	}

	return ans;
}







int main(){
	long long int rounds = 0;
	long long n,k,ans;
	string operato;

	rounds  = scan2();

	while(rounds--){
		n =scan2();
		k =scan2();
		ans = scan2();

		repeat(n){
			a[i] = scan2();
		}

		cin >> operato;

	cout << f(n,k,ans,operato) << "\n";
		ans = 0;
		ZERO(a);
		n = 0;
		k = 0; 


	}
	

	return 0;
}
 