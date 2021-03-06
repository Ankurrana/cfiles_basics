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

struct pair{
	long int l;
	long int r;
	unsigned long long int contains;
};




int main(){
	long int i = 0,k=0;
	long int boxes[100002];  //Contains the number of boxes.	
	long int n_boxes,box_no;
	long int m_pairs,flag;
	long int n_bursts;
	long int templ,tempr;
	long int belongsto[100][100];  //This contains the array of pairs a box belongs to
	long int ans_pre,ans,x,sum,j,y;
	struct pair pairs[100002];

	n_boxes = scan2();
	m_pairs = scan2();

	for(i=1;i<=n_boxes;i++){
		boxes[i] = scan2();
	}

	for(i=1;i<=m_pairs;i++){
		templ = scan2();
		tempr = scan2();
		pairs[i].l = templ;
		pairs[i].r = tempr;

		sum = 0;

		for(j=templ;j<=tempr;j++){
			sum += boxes[j];
		}

		pairs[i].contains = sum;
	}
	//Working fine upto this 

	for(i=1;i<=n_boxes;i++){
		for(j=1;j<=m_pairs;j++){
			if(pairs[j].l <= i && pairs[j].r >= i){
				belongsto[i][++belongsto[i][0]] = j;
			}
		}
	}

	// for(i=1;i<=n_boxes;i++){
	// 	printf("%ld box belongs to %d pairs\n",i,belongsto[i][0]);
	// 	for(j=1;j<=belongsto[i][0];j++){
	// 		printf("%d ",belongsto[i][j]);
	// 	}
	// 	printf("\n");
	// }



	n_bursts = scan2();
	ans_pre = 0;
	ans = 0;

	for(i=1;i<=n_bursts;i++){
		x = scan2();
		y = x + ans_pre;  //Now ans contains the index of the box of which the ballonng in burst;
		
		//printf("boxindex = %ld corresponding to x = %ld\n",y,x);

		for(k=1;k <= belongsto[y][0];k++){
			if(--pairs[belongsto[y][k]].contains == 0)
				ans++;
		}	

		printf("%ld\n",ans);
		ans_pre = ans;

	}

	return 0;
}