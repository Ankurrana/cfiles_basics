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

int a[39] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,137,139,149,151,157,163,167,173}; //these numbers shall produce primes till 31623

int i,m;
int booleanprimestill31623[31623] = {0}; //0 means prime // i.e primes from 0 to 31623
int primestill31623[100000];
long int p_counttill31623 = 0;
int booleanprimestill10_6[1000000] = {0};
long int primestill10_6[1000000] = {0};
long int p_counttill10_6 = 0;
//first calculate the primestill31623 till 10^5 in the main function


int isprime(long int n){
	// if(booleanprimestill31623[])
}



int doithaveprimeprimes(long int n){
	int count = 0;
	int mul = 1,i = 0;
	if(isprime(n))
		return 1;
	for(i=0;i<39;i++){
		count = 0;
		while(n%a[i] == 0){
			count++;
			n = n/a[i];
		}
		if(!isprime(count+1) || !isprime(mul*(count+1)))
			return 0;
		else{
			mul = (mul * (count+1));
		}
	}

	if(isprime(mul))
		return 1;
	else
		return 0;
}


int main(){
	// int i, size, m ,lower, upper, k;
 //    double div;
 //    int r[100000] = {0};
 //    int diff;
 //    b[0]=1;
 //    b[1]=1;
 //    for(i=0; i < 39; i++)
 //    {
 //             m=2*a[i]; 
 //             while(m<31623)
 //             {
 //                           b[m]=1;
 //                           m = m + a[i];
 //             }
 //    }  
 //    for(i=2; i<31623; i++)
 //    {
 //        if(b[i]==0)
 //           p[p_count++] = i;  
 //    }

	for(i=0;i<39;i++){
		m = 2*a[i];
		while(m<31624){
			booleanprimestill31623[m] = 1;
			m = m + a[i];
		}
	}

	//stacking them up

	for(i=2;i<=31623;i++){
		if(booleanprimestill31623[i] == 0)
			primestill31623[p_counttill31623++] = i;
	}


	for(i=0;i<p_counttill31623;i++){
		m = 2 * primestill31623[i];
		while(m<1000001){
			booleanprimestill10_6[p_counttill10_6++] = 1;
			m = m + primestill31623[i];
		}
	}

	// stacking them up

	for(i=2;i<1000000;i++){
		if(booleanprimestill10_6[i] == 0)
			primestill10_6[p_counttill10_6++] = i;
	}

	//Now this 


	for(i=0;i<p_counttill10_6;i++)
		printf("%ld ",primestill10_6[i]);


	return 0;
}