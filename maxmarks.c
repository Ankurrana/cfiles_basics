#include "stdio.h"
#include "stdlib.h"
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




struct question{
	double e;
	long int c,p,t,profit;
	

}q[110],temp;




int compare(const void *s1, const void *s2){
      struct question *e1 = (struct question *)s1;
      struct question *e2 = (struct question *)s2;
       
      if(e1->e > e2->e)
      	return 1;
      else
      	return 0;
}








void sort(long int k){
	int j,i;
	for(i=0;i<k;i++){
		for(j=0;j<k-i;j++){
			if(q[j].e > q[j+1].e){
				temp = q[j]
			}

		}
	}
}











int main(){
	long int testcases = 0,n_ques,total_marks = 0,w,i;
	testcases = scan2();
	while(testcases--){
		total_marks = 0;
		n_ques = scan2();
		w = scan2();

		for(i=0;i<n_ques;i++){
			q[i].c = scan2();
			q[i].p = scan2();
			q[i].t = scan2();
			q[i].profit = q[i].c * q[i].p;
			q[i].e = (double)q[i].profit/(double)q[i].t;
		}

		qsort(q, n_ques, sizeof(struct question), compare);

		for(i=0;i<n_ques;i++){
			if(total_marks + q[i].profit <= w )
				total_marks += q[i].profit;
		}


		for(i=0;i<n_ques;i++)
			printf("%ld\n\n",q[i].t);

		printf("%ld\n",total_marks);

	}
	return 0;
}