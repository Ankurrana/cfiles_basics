#include "stdio.h"
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


int main(){
	long long int testcases = 0,a[200] = {0},k = 0,n = 0,i = 0,key = 0,temp,j = 0;
	int count = 0;

	testcases = scan2();
	while(testcases--){
		count = 0;
		n = scan2();
		
		for(i=0;i<n;i++)
			a[i] = scan2();

		k = scan2();
		k--;


		for(i=0;i<n;i++){
			if(a[i]<a[k])
				count++;
		}

			printf("%d\n",count+1);

	}	
	return 0;
}