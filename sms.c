#include "stdio.h"
#define get getchar_unlocked

inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

long long int sqare(long long int s){
	
}

int main(){
	int rounds = 0,i,a,n;
	rounds = scan2();
	while(rounds--){
		n = scan2();

	}	
	return 0;
}