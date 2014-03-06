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


int main(){
	long int a,k,n,i = 0;
	
	a = scan2();
	k = scan2();
	n = scan2();

	for(i=0;i<n;i++){
		printf("%ld ",a%(k+1));
		a = a/(k+1);
	}

	return 0;
}