#include "stdio.h"
int main(){
	int i;
	int sum = 0;
	int val;
	int rounds;

	scanf("%d",&rounds);
	int temp = rounds;

	while(rounds--){
		scanf("%d",&val);

	for(i=11;i>=0 && val;i--){
		sum += val/(1<<i);
		val  = val%(1<<i);
	}

		printf("%d\n",sum);
		sum = 0;
	}

	
	return 0;	
}