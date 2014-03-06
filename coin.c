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
	long int coins = 0,rounds = 0,games = 0,iside = 1,rside = 1;
	rounds = scan2();
	while(rounds-- ){
		
		games = scan2();
		while(games--){
			iside = scan2();
			coins = scan2();
			rside = scan2();
			if(coins%2 == 0)
				printf("%ld\n",coins/2);
			else if(rside == iside){
				printf("%ld\n",(coins-1)/2 );
			}
			else{
				printf("%ld\n",(coins+1)/2);
			}
		}
	}

	return 0;
}