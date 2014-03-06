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
	long int n,i,temp;
	n = scan2();
	// scanf("%ld",&n);
	for(i=0;i<n;i++){
		// scanf("%ld",&temp);
		temp = scan2();
	};
	printf("%ld\n",n);
	for(i=n;i>0;i--){
		printf("%ld 1\n",i);
	}
	return 0;
}