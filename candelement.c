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
	long long int rounds = 0,ele = 0,sum = 0,temp = 0,candies = 0;
	rounds = scan2();
	while(rounds--){
		sum  = 0;
		ele = scan2();
		candies = scan2();
		while(ele--){
			temp = scan2();
			sum = sum + temp;
		}
		if(sum <= candies)
			printf("Yes\n");
		else
			printf("No\n");
	}	
	return 0;
}