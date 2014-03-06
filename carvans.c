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
	long int rounds = 0,cars = 0,i,maxspeed = 0,speed = 0,carswithmaxspeed = 1;
	rounds = scan2();
	while(rounds--){
		cars = scan2();

		maxspeed = scan2();

		for(i=1;i<cars;i++){
			speed = scan2();
			if(speed <= maxspeed){
				carswithmaxspeed++;
				maxspeed = speed;
			}
		}
		printf("%ld\n",carswithmaxspeed);
		carswithmaxspeed= 1;
	}	
	return 0;
}