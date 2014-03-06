#include "stdio.h"
#include "math.h"
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
	long long int a,b,testcases = 0,i,j;	
	int primes[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
	double k = 0.00;
	int ans = 0;
	a = 1;
	b = 10;



	// printf("%d",log(a)/==log(b));
	while(testcases--){
		ans = 0;
		for(i=0;i<12;i++){
			for(j=0;j<12;j++){
				k = (double)((double)primes[j]-1)*log10(primes[i]);
				printf("a = %f b = %f  k =%f\n",log10(a),log10(b),k);
				if(k >= log10(a) && k<=log10(b)){
					ans++;
					printf("Inceremented");
				}
			}
		}
	}

	printf("%d",ans);

	return 0;
}