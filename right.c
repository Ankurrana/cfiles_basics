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
	long long int triangles = 0,x1,y1,x2,y2,x3,y3,a,b,c;
	long long int righttriangles = 0;

	scanf("%lld",&triangles);
	while(triangles--){
		//scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
		x1 = scan2();
		y1 = scan2();
		x2 = scan2();
		y2 = scan2();
		x3 = scan2();
		y3 = scan2();

		a = (x1 - x2)*(x1-x2) + (y1-y2)*(y1-y2);
		b = (x1-x3)*(x1-x3) + (y1 - y3)*(y1 - y3);
		c = (x2-x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);

		if(a+b == c || b+c == a || c+a == b)
			righttriangles++;
	}

	printf("%lld\n",righttriangles);
	return 0;
}