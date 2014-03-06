#include "string.h"
#include "stdio.h"

int main(){
	char jewelstring[201];
	int rounds,count=0;
 	int a[58],i;
	scanf("%d",&rounds);


	for(i=0;i<58;i++){
		a[i] = 0;
	}

	while(rounds--){
		scanf("%s",jewelstring);
		i=0;
		while(jewelstring[i]!='\0' && i<201){
			a[(int)jewelstring[i]-65]++;
			i++;
		}

		for(i=0;i<58;i++){
			count = count + a[i]/2 + a[i]%2;
			a[i] = 0;
		}


		printf("%d\n",count);
		count = 0;

	}

			

	return 0;
}