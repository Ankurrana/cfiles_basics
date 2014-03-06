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

	int counts = 0;


void quick_sort (int *a, int n) {
    if (n < 2)
        return;
    else{
    	counts += n;
    	printf("n = %d \t counts =  %d\n ",n,counts );
    }
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    

    printf("pivot = %d\n",p);
    while (l <= r) {
        if (*l < p) {
            l++;
            continue;
        }
        if (*r > p) {
            r--;
            continue; // we need to check the condition (l <= r) every time we change the value of l or r
        }
        int t = *l;
        *l++ = *r;
        *r-- = t;
   }



    quick_sort(a, r - a + 1);
    quick_sort(l, a + n - l);
}






int main(){
	int a[] = {4,3,5,1,2};
    int n = sizeof a / sizeof a[0];
    printf("%d\n",n);
    int i;
    quick_sort(a, n);

    for(i=0;i<n;i++){
    	printf("%d ",a[i]);
    }

    printf("\n%d",counts);
    return 0;	
	return 0;
}