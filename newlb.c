#include "stdio.h"
#define get getchar_unlocked
#include <stdlib.h>  
inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


long int rounds,n,bamboos[60],diff[60],c_bamboos[60],sum = 0,reducer = 0,count = 0,even = 0,odd = 0,all_not_same = 0,i;	

int main(){
	rounds = scan2();	
	while(rounds--){
		even = 0;
		odd = 0;
		count = 0;
		sum = 0;
		all_not_same = 0;

		n = scan2();
		reducer = n-2;
		for(i=0;i<n;i++)
			bamboos[i] = scan2();
		for(i=0;i<n;i++)
			c_bamboos[i] = scan2();
		for(i=0;i<n;i++){
			diff[i] = c_bamboos[i] - bamboos[i];
			sum += diff[i];
			if(diff[i]< 0)
				count++;
			if( abs(diff[i])%2 == 0)
				even = 1;
			else
				odd = 1;



			if( abs(diff[0] != labs(diff[i])) )
				all_not_same = 1;

		}
		if( n == 1 ){
			if(diff[0]< 0)
				printf("%ld\n",-1*diff[0] );
		}
		else if( (even == 1 && odd == 1)  || count > 1 )
			printf("1::-1\n");
		else if(count == 1 && all_not_same == 0 )
			printf("2::%ld\n",labs(diff[0]) );
		else if(count==0){
			if(even == 1 && odd == 0 ){
				if(sum%reducer == 0 && (sum/reducer)%2 == 0 ){
					printf("3::%ld\n",sum/reducer);
				}
				else{
					printf("4::-1\n");
				}
			}
			else if(odd == 1 && even == 0){
				if(sum%reducer == 0 && (sum/reducer)%2 == 1){
					printf("5::%ld\n",sum/reducer);
				}
				else{
					printf("6::-1\n");
				}
			}
			else{
				printf("7::-1\n");
			}

		}
		else{
			printf("8::-1\n");
		}



	}
		
	return 0;
}