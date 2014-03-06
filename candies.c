#include "stdio.h"
int main(){
	unsigned long long int candies,students;
	unsigned short int rounds;
	scanf("%d",&rounds);
	while(rounds--){
		scanf("%lld %lld",&candies,&students);
		if(students != 0)
			printf("%lld %lld\n",candies/students,candies%students);
		else
			printf("0 %lld",candies);

	}

	return 0;
}