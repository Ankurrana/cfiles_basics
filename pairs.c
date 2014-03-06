#include "stdio.h"
#define get getchar_unlocked

inline long long int scan2(){
	long long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


int main(){
	
	long long int testcases = 0,n,a;
	testcases = scan2();

	while(testcases--){
		n = scan2();a = (n*(n-1))/2;printf("%lld\n",a);while(n--){scan2();}}


	return 0;
}