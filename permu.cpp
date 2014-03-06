#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
using namespace std;
#include <climits>
 
typedef unsigned long long uint64;
#define get getchar_unlocked
#define repeat(n) for (int i = (1); i <= n; i++)
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

int main(){
	int l = 0;
	int a[1010] = {0};
	bool traversed[1010] = {false};
	int first = 0;
	int nooftransersals = 0;
	int k;
	l = scan2();
	int next = 0;
	int loops = 0;
	repeat(l)
		a[i] = scan2();


	int ans[1010][1010];	
	int sol = 0;
	k = 0;
	
	while(nooftransersals <  l){
		

		repeat(l){
			if(traversed[i] == false){	
				first = i;
				break;
			}
		}

		next = first;

		k = 0;
		do{
			// printf("%d ",next);
			ans[loops][k++] = next;
			traversed[next] = true;	
			next = a[next];
			nooftransersals++;

		}while(next != first);

		// printf("%d\n",first);
		ans[loops][k++] = first;


		ans[loops][k++] = -1;
		loops++;

	}


		printf("%d\n",loops);
		
		for(int i=0;i<loops;i++){
			for(int j=0;ans[i][j] != -1;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
			
	return 0;
}
 