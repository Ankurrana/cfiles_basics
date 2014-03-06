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
#define repeat(n) for (int repc = (n); repc > 0; --repc)
#define ZERO(v) memset((v), 0, sizeof (v))
#define ALL(x) (x).begin(), (x).end()
 


struct student
{
	int a,b;
	student(){
		scanf("%d%d",&a,&b);
	}
};


int main(){
	cin.sync_with_stdio(0);

  	student s;
  	
  	s = student.studento();
  	printf("%d\n",s.a);

	return 0;
}
 