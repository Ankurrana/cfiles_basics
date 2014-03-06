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

void sieve( long int *a, long int n){
	 long int i, j;

	for(i=2; i<=n; i++)
		a[i] = 1;  //assuming 1 for prime, initially all are considered prime
	for(i=2; i<=n; i++){
		if(a[i] == 1){
			for(j=i; (i*j)<=n; j++)
				a[(i*j)] = 0;
		}
	}
}

int main(){
	long long int a,b,testcases = 0,i,j;	
	long int primes[(long int)500000];
	long int boolean[(long int)500000];
	double k = 0.00;
	int ans = 0;

	sieve(primes,(long int)1000000);


	testcases = scan2();

	while(testcases--){
		ans = 0;
		a = scan2();
		b = scan2();
		for(i=0;i<39;i++){
			for(j=0;j<39;j++){
				k = (double)((double)primes[j]-1)*log(primes[i]);
				// printf("a = %f b = %f  k =%f\n",log(a),log(b),k);
				if(k >= log(a) && k<=log(b)){
					ans++;
					// printf("Inceremented");
				}
			}
		}
		printf("%d\n",ans);
	}

	

	return 0;
}