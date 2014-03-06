#include "stdio.h"
#define get getchar_unlocked

inline int scan2(){
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

int main(){
	int t = 0,i=0;
	int a[11];
	int minindex=100;
	int minfre=100;
	t = scan2();
	while(t--){
		for(i=0;i<10;i++){
			a[i] = scan2();
		}

		for(i=1;i<=9;i++){
			if(a[i]<minfre){
				minfre = a[i];
				minindex = i; 				
			}
		}

		if(a[0]<minfre){
			printf("1");
			for(i=0;i<=a[0];i++)
				printf("0");
		}
		else{
			for(i=0;i<=minfre;i++)
				printf("%d",minindex);
		}

		printf("\n");
		minfre =1000;
		minindex =1123;

	}
	return 0;
}