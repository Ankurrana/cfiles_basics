#include "stdio.h"
#include "stdlib.h"

int main(){
	long int n,k,i;
	long int nums,count = 0;

	scanf("%ld%ld",&n,&k);

	for(i=0;i<n;i++){
		scanf("%ld",&nums);
		if(nums%k == 0)
			count++;
	}

	printf("%ld",count);
	return 0;

}