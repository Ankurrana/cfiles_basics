#include "stdio.h"
#define get getchar_unlocked



inline unsigned long long int scan2(){
    unsigned long long int n=0,s=1;
    char p=get();
    if(p=='-') s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}

unsigned long long gcd(unsigned long long c, unsigned long long j){
  return j?gcd(j,c%j):c;
   
 
}
unsigned long long func(unsigned long long n, unsigned long long k){
  unsigned long long c = 1 , j;
  
  
  for(j=1;j<=k;j++){
    unsigned long long d = gcd(c,j);
    c/=d;
    c= c*((n-j+1)/(j/d));
    
  }
  
  return c;
}


int main(){
	unsigned long long int n,k,s,m,result = 1,i = 1,max,min;
	 s = scan2();

	while(s--){
        n = scan2();
        k = scan2();

        if(k>n){
            printf("0\n");
            continue;
        }
        if(n == k){
            printf("1\n");
            continue;
        }
		printf("%llu\n",func(n,k));
	}
	return 0;
}


