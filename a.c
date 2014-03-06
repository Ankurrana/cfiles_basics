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
	long int rounds = 0,n = 0;
	rounds = scan2();
	while(rounds--){
		n = scan2();
		if(n%2 == 0)
			printf("ALICE\n");
		else
			printf("BOB\n");
	}

}


