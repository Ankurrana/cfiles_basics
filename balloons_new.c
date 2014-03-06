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


unsigned long long int sums[100000] = {0};  //cumutative sum of baloons
long int boxes[100001] = {0};	//individual balloons
long int reductions[100001] = {0}; //reduction in each box

int valid_pair[100010] = {0}; 


struct pair {
	long int l;
	long int r;
};

int main(){
	long int n = 0,flag = 0;
	long int m = 0;
	long int i = 0,temp = 0,sum = 0 ,ans = 0,b = 0 ,x = 0,k = 0,v = 0,red_sum = 0;
	long int j = 0;
	
	struct pair pairs[100001];
	// scanf("%ld %ld",&n,&m);
	n = scan2();
	m = scan2();
	
	for(i = 1;i <= n;i++){
		// scanf("%ld",&boxes[i]);
		boxes[i] = scan2();
		// sum = sum + temp;
		// sums[i] = sum;
	}	

	for(i = 1;i<=m;i++){
		// scanf("%ld %ld",&pairs[i].l,&pairs[i].r);
		pairs[i].l = scan2();
		pairs[i].r = scan2();
	}

	
	// scanf("%ld",&b);
	b =scan2();

	ans = 0;

	for(i=1;i<=b;i++){

		// scanf("%ld",&x);
		x = scan2();
		x = x + ans;
		reductions[x]++;

		if(--boxes[x] == 0){

			for(j=1;j<=m;j++){

				if(valid_pair[j] != 0)
					continue;


				for(v = pairs[j].l;boxes[v]==0 && v<=pairs[j].r;v++);
					if(v > pairs[j].r){
						valid_pair[j] = 1;
						ans++;

					}
			}
		}
		printf("%ld\n",ans);


	}

	
	return 0;
}


