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

inline long long int bigmod(long int a,long int b,long int m)
{
	if(b == 0) return 1 % m;
	long int x = a, ans = 1;
	while(b){
		if(b&1) ans = (ans * x)%m;
		b >>= 1;
		x = (x*x)%m;
	}	
	return ans;
}

long int c_factoristion_addition[100010][25] = {0};


int main(){
	long int i = 0,j = 0;
	long int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	long int primefactorisation[110][26] = {0};
	long int n,k = 0;
	long int queries = 0;
	long int temp[25] = {0};
	long int prime_number;
	long int l = 0 , r=0 ,m=0,cnt=0;
	long long int ans = 1;

	for(i=2;i<=100;i++){
		k = i;
		for(j=0;j<25 && k > 1;j++){
			prime_number = primes[j];
			while(k>1){
				if(k % prime_number == 0){
					primefactorisation[i][j]++;
					k = k/prime_number;
				}
				else
					break;
			}
		}
	}


	n = scan2();

	for(i=1;i<=n;i++){
		k = scan2();


		for(j=0;j<25;j++){
			temp[j] += primefactorisation[k][j]; 		
			c_factoristion_addition[i][j] = temp[j];
			
		}

	}


	//Now then , i have the cumulative frequecies

	
	queries = scan2();
	
	while(queries--){
		l = scan2();
		r = scan2();
		m = scan2();



		ans = 1 % m;
		for(j = 0; j < 25; j++)
		{
			cnt = c_factoristion_addition[r][j] - c_factoristion_addition[l-1][j];
			if(cnt) ans = (ans * bigmod(primes[j], cnt, m))%m;
			if(ans == 0) break;
		}

		printf("%lld\n",ans);


	}


	return 0;
}