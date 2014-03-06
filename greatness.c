#include "stdio.h"
#include "math.h"
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

int num_digits(long long int x){
	
	if(x>=1000000000) return 10;
    if(x>=100000000) return 9;
    if(x>=10000000) return 8;
    if(x>=1000000) return 7;
    if(x>=100000) return 6;
    if(x>=10000) return 5;
    if(x>=1000) return 4;
    if(x>=100) return 3;
    if(x>=10) return 2;
    return 1;
}


int main(){
	long long int t,s,e,sum,i;
	t = scan2();
	while(t--){
		sum = 0;
		s = scan2();
		e = scan2();
		for(i=1;i<=10000000000;i++){
			sum = (sum + i*num_digits(i))%1000000007;
		}
		printf("%lld\n",sum);
	}


	return 0;
}