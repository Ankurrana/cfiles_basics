#include "stdio.h"
#define get getchar_unlocked
#include "string.h"

typedef unsigned long long uint64;

inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

uint64 f(uint64 n,uint64 k,uint64 tempans,int o,uint64 a[]){

		uint64 ans = a[1];
		uint64 j;
		for(j=2;j<=n;j++){
			
			if(o == 1)
				ans = ans^a[j];
			else if(o == 2)
				ans = ans | a[j];
			else
				ans = ans & a[j];
		}
		
		if(o == 2)
			return ans|tempans;
		else if(o==3)
			return ans&tempans;
		else{
			if(k%2 == 0)
				return tempans;
			else{
				return tempans^ans;
			}


		}
						

		
}


int main(){
	uint64 t = 0,n,k,ans,a[1010],tempans,i;
	int o;
	char op[10];
	t = scan2();
	while(t--){
		n = scan2();
		k = scan2();
		tempans = scan2();


		for(i=1;i<=n;i++)
			a[i] = scan2();

		scanf("%s",op);

		if(strcmp(op,"XOR") == 0)
				o = 1;
		else if(strcmp(op,"OR") == 0)
				o = 2;
		else
			o = 3;

		if(k==0){
			printf("%lld\n",tempans);
		}
		else{
			 printf("%lld\n",f(n,k,tempans,o,a));
		}


	}	
	return 0;
}