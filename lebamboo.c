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
	int rounds,n,e_bamboos[60],c_bamboos[60],i,j,sum = 0,reducer = 0,steps = 0,is_odd = 0,flag = 0;
	rounds = scan2();
	while(rounds--){
		flag = 0;
		sum = 0;
		steps = 0;
		n = scan2();
		for(i=0;i<n;i++)
			e_bamboos[i] = scan2();
		for(i=0;i<n;i++)
			c_bamboos[i] = scan2();

		for(i=0;i<n;i++){
			e_bamboos[i] = c_bamboos[i] - e_bamboos[i];
			sum = sum + e_bamboos[i];
		}
		if(n==1){

			if(e_bamboos[0]!= 0)
				printf("-1\n");
			else 
				printf("0\n");
		
			continue;
		}
		if(n==2){

			if(e_bamboos[0] + e_bamboos[1] == 0)
					printf("%d\n",abs(e_bamboos[0]));
			else
				printf("-1\n");


			continue;
		}		

			reducer = n-2;

			if(sum%reducer != 0){
				printf("-1\n");
				continue;
			}
			else{

				steps = sum/reducer;

				if(steps%2 == 0){
					for(i=0;i<n;i++){
						if(e_bamboos[i]%2 != 0){
							printf("-1\n");
							flag = 1;
							break;
						}
					}

				}
				else{
					for(i=0;i<n;i++){
						if(e_bamboos[i]%2 == 0){
							printf("-1\n");
							flag = 1;
							break;
						}
					}
				}

				if(flag == 0)
						printf("%d\n",steps);
			}

	}
	return 0;
}