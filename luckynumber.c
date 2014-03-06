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

long int solve(long int n){
	switch(n%7){
		case 0:
			return n;
		case 1:
			return (n-8>=0)?(n-8):-1;
		case 2:
			return (n-16>=0)?(n-16):-1;
		case 3:
			return (n-24>=0)?(n-24):-1;
		case 4:
			return (n-4>=0)?(n-4):-1;
		case 5:
			return (n-12>=0)?(n-12):-1;
		case 6:
			return (n-20>=0)?(n-20):-1;	
	}
}


int main(){
	long int rounds = 0,n,i,j;
	rounds = scan2();
	while(rounds--){
		printf("%ld\n",solve(scan2()));
	}
	return 0;
}