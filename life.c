#include "stdio.h"

int main(){
	int i[100],j=0,k,count,flag=1 ;
	
	while(1){
		scanf("%d",&i[j]);
		if((i[j++] == 42) && flag){
			count = j;
			flag = 0;
		}
		if(!flag && i[j-1]>=99){
			break;
		}
	}


	for(k=0;k<(count-1);k++)
		printf("%d\n",i[k]);

	return 0;
}