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
	long int a[100001],i,n,q,l,r,k,count = 0,j;
	n = scan2();
	q = scan2();
	for(i=1;i<=n;i++)	
		a[i] = scan2();
	for(i =1;i<=q;i++){
		l =	scan2();
		r = scan2();
		k =	scan2();
		for(j = l;j<=r;j++){
			if(a[j] > k && a[j]%k == 0)
				count++;
		}
		printf("%ld\n",count);
		count = 0 ;

	}


	return 0;
}