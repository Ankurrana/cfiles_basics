#include "stdio.h"
#define get getchar_unlocked

inline int scan2(){
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

int main(){
	int a,b,c=0;
	a = scan2();
	b = scan2();

	c = a-b;

	if((c%10)<9){
		printf("%d",c+1);
	}
	else{
		printf("%d",c-1);
	}


	return 0;
}