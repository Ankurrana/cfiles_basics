#include "stdio.h"
#define get getchar_unlocked
#include "math.h"

inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


double dis(int x,int y,int p,int q){
	double a = pow(abs(x - p),2) + pow(abs(q-y),2);
	return sqrt(a);
}




int main(){
	long int rounds,x1,y1,x2,y2,x3,y3,range,dis1,dis2,dis3,outer,d;
	int count = 0,k;
	rounds = scan2();
	while(rounds--){
		count = 0;
		range = scan2();
		x1 = scan2();
		y1 = scan2();
		x2 = scan2();
		y2 = scan2();
		x3 = scan2();
		y3 = scan2();

		dis1 = dis(x1,y1,x2,y2);
		dis2 = dis(x2,y2,x3,y3);
		dis3 = dis(x3,y3,x1,y1);

		if(dis1 > range){
			count++;
			d = 1;
		}

		if(dis2 > range){
			count++;
			d = 2;
		}
		if(dis3 > range){
			count++;
			d = 3;
		}

		k = 0;
		if(count>=2)
			printf("no\n");
		else{
			switch(d){
				case 1:
					if( (dis2 + dis3)<=range )
						k = 1;
					break;
				case 2:
					if( (dis1 + dis3)<=range )
						k = 1;
					break;
				case 3:
					if( (dis1+dis2)<= range)
						k = 1;
					break;
			}
			if(k)
				printf("yes\n");
			else
				printf("no\n");
		}

	}

	return 0;
}