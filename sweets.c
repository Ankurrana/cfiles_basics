#include "stdio.h"
#define get getchar_unlocked

int main(){
	int t,n,c,i,min=10000,sum=0,temp = 0;
	scanf("%d",&t);
		
	while(t--){
		scanf("%d %d",&n,&c);
		sum = 0;
		min = 10000;
		
		while(n--){
			scanf("%d",&temp);
			sum = sum + temp;
			if(min>temp)
				min = temp;
		}


		if(sum%c >= min)
			printf("-1\n");
		else
			printf("%d\n",sum/c);
		
	}	
	return 0;
}