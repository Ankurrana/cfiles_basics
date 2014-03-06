#include "stdio.h"
#define get getchar_unlocked

inline  int scan2(){
	 int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

int gcd_iter(int u, int v) {
  int t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; 
}


int main(){
	
	int t,i,j,n,old,new,gcd;
	int a[1010]= {0};
	t = scan2();
	while(t--){
		n = scan2();		
		for(i=0;i<n;i++)
			a[i] = scan2();

		old = a[0];
		gcd = a[1];
		for(i=1;i<n;i++){
			gcd = gcd_iter(old,a[i]);
			old = gcd;
		}


		for(i=0;i<n;i++)
			printf("%d ",a[i]/gcd);

		printf("\n");
	}

	return 0;
}