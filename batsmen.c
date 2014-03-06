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

long int f(long int n){
	return (n==1)?1:n*f(n-1);
}
	


int main(){
	long int t,npl,i,count[110]={0},total,required,permu,k,temp;
	t = scan2();
	
	while(t--){
		k = 0;

		for(i=0;i<=110;i++)
			count[i] = 0;

		for(i=1;i<=11;i++){
			temp = scan2();
			count[temp]++;
		}

		npl = scan2();

		for(i=100; i>=1 && k<npl ;){
			if(count[i]>0){
				k = k + count[i];
				// printf("\ncount[%ld]= %ld where k = %ld",i,count[i],k);
			}
			i--;
		}	
		i++;
		
		k = k - count[i];
		total = count[i];
		required = npl - k;

		permu = f(total)/( f( total-required )* f(required) );

		printf("%ld\n",permu);
	}
	return 0;
}