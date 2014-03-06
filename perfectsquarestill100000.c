#include "stdio.h"
#define get getchar_unlocked

inline long long int scan2(){
	long long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

int check(long long int n){
	long long int k = 0;
	while(n>0){
		k = n%10;
		if( !(k == 0 || k==1 || k==4 ||k==9 ))
			return 0;
		n = n/10;
	}
	return 1;
}


int main(){
	long long int i,a,b,count = 0,nums[122],testcases = 0,ans = 0;

	for(i=0;i<=100000;i++){
		if(check(i*i)){
			nums[count++] = i*i;
		}
	}

	testcases = scan2();
	while(testcases--){
		a = scan2();
		b = scan2();	
		ans = 0;

		for(i=0;i<count;i++){
			if(nums[i]>=a && nums[i]<=b)
				ans++;
			else if(nums[i]>b)
				break;
		}

		printf("%lld\n",ans);

	}

	
	return 0;
}