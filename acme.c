#include "stdio.h"
#define get getchar_unlocked

inline  int scan2(){
	 int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


int printIntersection(int arr1[], int arr2[], int m, int n)
{
  int i = 0, j = 0,count = 0;
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
	int common,i,m,n,s[110],t[110],testcases = 0,k = 0;
	testcases = scan2();
	while(testcases--){
		common = 0;
		k = 0;
		m = 0;
		n = 0;
		
		m = scan2();
		for(i=0;i<m;i++)
			s[i] = scan2();
		
		n = scan2();

		for(i=0;i<n;i++)
			t[i] = scan2();


		common = printIntersection(s,t,m,n);
		

		if(m>=n)
			k = m;
		else
			k = n;

		printf("%d\n",k-common);
	}
	return 0;
}