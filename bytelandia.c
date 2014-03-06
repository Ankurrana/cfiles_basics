#include "stdio.h"
#include "stdlib.h"
#define get getchar_unlocked
#define repeat(n) for(i=0;i<(n);i++);
inline int scan2(){
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

inline int compare (const void * a, const void * b){
  return ( *(struct aasd*)a.times - *(struct aasd*)b.times );
}


struct aasd{
	int times;
	int isarrival;
}ad[210];

int main(){
	int rounds=0;
	int arrival[110]={0},departure[110] = {0},n = 0,i=0;
	rounds = scan2();	
	while(rounds--){
		n = scan2();

		for(i=0;i<n;i++){
			ad[i].times = scan2();
			ad[i].isarrival = 1;
		}	
		for(i=n;i<2*n;i++){
			ad[i].times = scan2();
			ad[i].isarrival = 0;
		}


		qsort(ad,2*n,sizeof(struct aasd),compare);
		// qsort(departure,n,sizeof(int),compare);

		//Here goes the actual algorithm




	}	
	return 0;
}