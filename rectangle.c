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
	int mat[310][310] = {0};
	long int q,x1,y1,x2,y2,n,i,j,count = 0,a[11];

	n = scan2();

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			mat[i][j] = scan2();
		}
	}

	q = scan2();

	while(q--){
		x1 = scan2();
		y1 = scan2();
		x2 = scan2();
		y2 = scan2();

		for(i=1;i<=10;i++)
			a[i] = 0;

		for(i=x1;i<=x2;i++){
			for(j=y1;j<=y2;j++){
				a[mat[i][j]]++;
			}
		}

		count = 0;

		for(i=1;i<=10;i++)
			if(a[i]>0)
				count++;

		printf("%ld\n",count);

	}

	return 0;
}