#include "stdio.h"
#include "malloc.h"
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


void sieve(long  int *a,long  int n){
	long  int i, j;
	for(i=2; i<=n; i++){
		if(a[i] == 0){
			for(j=i; (i*j)<=n; j++)
				a[(i*j)] = 1;
		}
	}
}

int main()
{
	long int *a, n,i,p_count = 0; //0 means prime
	long int primes[1000000];
	a =(long int *)malloc(n * sizeof( long int));

	for(i=0;i<1000000;i++)
		a[i] = 0;  // assuming 0 to be true for prime


	sieve(a,1000000);


	//stacking 'em up;

	

	for(i=0;i<1000000;i++){
		if(a[i] == 0)
			primes[p_count++] = i;
	}

	for(i=0;i<p_count;i++)
		printf("%ld",primes[i]);

	return 0;
}












