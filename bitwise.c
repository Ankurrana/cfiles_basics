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
	
	int n = 0;
	long int i,j,nums[1000000];
	long long int sum = 0,temp = 0,flag = 0,c = 0;
	long numones = 0;
	n = scan2();

	for(i=0;i<n;i++){
		c = scan2();	
		nums[i] = c;
		if(c==1)
			numones++;
		if(c!=1 || c!=0)
			flag = 1;
		
	}

	if(flag == 1){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				 sum += (nums[i] & nums[j]);
			}
		}
	}
	else{
		if(numones%2 == 0){
			sum = (numones/2)*(numones-1);
		}else{
			sum = ((numones-1)/2)*numones;
		}
	}



	printf("%lld",sum);
	sum = 0;
	numones = 0;

	return 0;
}