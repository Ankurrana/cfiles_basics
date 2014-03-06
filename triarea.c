#include "stdio.h"
#include "math.h"
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
	int n,x1,x2,x3,y1,y2,y3,i,min,max,temp,maxarea = 0,minarea = 32000;
	n = scan2();
	for(i=1;i<=n;i++){
		x1 = scan2();
		y1 = scan2();
		x2 = scan2();
		y2 = scan2();
		x3 = scan2();
		y3 = scan2();

		temp = abs(x1*(y2-y3)+ x2*(y3-y1) + x3*(y1-y2));


		if(temp >= maxarea){
			maxarea = temp;
			max = i;
		}
		if(temp <= minarea){
			minarea = temp;
			min = i;
		}

	}

	printf("%d %d",min,max);	
	return 0;
}