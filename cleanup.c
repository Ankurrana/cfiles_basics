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
	int a[1010] = {0};
	int t,n,m,i,temp;
	t = scan2();
	int assistant[1010] ={0};
	int chef[1010] = {0};
	int c = 0,as = 0,even = 0;

	while(t--){
		n = scan2();
		m = scan2();
		c = 0;
		as = 0;
		even = 0;

		for(i=0;i<=n;i++)
			a[i] = 0;



		for(i=0;i<m;i++){
			temp = scan2();
			a[temp] = 1;  // All numbers where the job is done are 1
		}

		for(i=1;i<=n;i++){
			if(a[i] == 0){
				if(!even){
					chef[c++] = i;
					even = 1;					
				}
				else{
					assistant[as++] = i;
					even = 0;
				}

			}
		}

		for(i=0;i<c;i++)
				printf("%d ",chef[i]);
		printf("\n");
		for(i=0;i<as;i++)
				printf("%d ",assistant[i]);

		printf("\n");


	}	
	return 0;
}