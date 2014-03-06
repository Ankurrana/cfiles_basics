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
	long int i,j,n,rounds,cost,minnote = 10000;
	rounds = scan2();



	while(rounds--){
		
		minnote = 1000;
		n = scan2();
		cost = scan2();

		while(n--){

		}
	}
	return 0;
}