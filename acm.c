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

long int printIntersection(long int arr1[],long int arr2[],long int m,long int n)
{
  long int i = 0, j = 0,count = 0;
  count = 0;
  while(i < m && j < n)
  {
    if(arr1[i] < arr2[j])
      i++;
    else if(arr2[j] < arr1[i])
      j++;
    else
    {
      count++;
      i++;
      j++;
    }
  }
  return count;
}

int main(){
	long int testcases = 0,m,n,c[110],count = 0,a[110],b[110],t,common = 0,min = 0,i;
	testcases = scan2();
	while(testcases--){
		common = 0;	
		for(i=0;i<110;i++)
			c[i] = 0;

		count = 0;
		m =scan2();

		for(i=0;i<m;i++){
			t = scan2();
			c[t]++;
			a[i] = t;
		}
		n = scan2();

		for(i=0;i<n;i++){
			t = scan2();
			c[t]++;
			b[i] = t;
		}

		common = printIntersection(a,b,m,n);


		for(i=1;i<=100;i++)
			if(c[i] == 1){
				count++;
			}
		min = (m-common)>=(n-common)?n-common:m-common;

		printf("%ld\n",count-min);

	}	
	return 0;
}