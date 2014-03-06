#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
#include <cstdlib>
using namespace std;
#include <climits>
#define get getchar_unlocked

 
typedef unsigned long long uint64;
#define repeat(n) for (int repc = 0; repc < n; repc++)
#define ZERO(v) memset((v), 0, sizeof (v))
#define ALL(x) (x).begin(), (x).end()
 
inline int scan2(){
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
	int rounds;
	int a[10023],n = 0,temp = 0;
	

	int nums[120] = {0};

	rounds = scan2();
	int k = 0;
	int p = 0;
	while(rounds--){

		//memset(a,0,sizeof(a));
		//memset(nums,0,sizeof(nums));

		ZERO(a);
		ZERO(nums);


		k = 0;
		p = 0;

		n = scan2();
		
		while(n--){
			temp = scan2();
			a[temp]++;
			nums[k++] = temp;
		}

		qsort(nums,k,sizeof(int),compare);

		int y = -1;

		repeat(k){
			if(nums[repc] != y){
				nums[p++] = nums[repc];
				y = nums[repc];
			}
		}

		int maxfrequency = 0,numberwithmaxfrequency = -1;

		repeat(p){
			if(a[nums[repc]] > maxfrequency ){
				maxfrequency = a[nums[repc]];
				numberwithmaxfrequency = nums[repc];
			}
		}

		printf("%d %d\n",numberwithmaxfrequency,maxfrequency);


	}


	return 0;
}
 