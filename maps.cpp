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
#include "map"
 
typedef unsigned long long uint64;
#define get getchar_unlocked
#define repeat(n) for (int i = (0); i < n; i++)
#define ZERO(v) memset((v), 0, sizeof (v))
#define ALL(x) (x).begin(), (x).end()
 

inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

struct  points
{
	long long int x,y;
	bool killed;
} demons[1010];

long int rounds = 0,i = 0,numpoints = 0,x,y,j;
map <long long int, int >X;
map <long long int, int >Y;

int main(){
	int demonnumber = 0;
	map< long long int,int > :: iterator it = X.begin();
	int count = 0;
	
	rounds = scan2();
	while(rounds--){
		count = 0;	
		numpoints = scan2();
		
		for(i = 1; i<= numpoints;i++){
			x = scan2();
			y = scan2();

			X[x]++;
			Y[y]++;

			demons[i].x = x;
			demons[i].y = y;
			demons[i].killed = false;
		}



		for(i=1;i<=numpoints && demons[i].killed == false;i++){
			
				count++;
				printf("Count incremented  %d\n",count);



				if( X[demons[i].x] > Y[demons[i].y]){

					for(j=1; j<=numpoints && X[demons[i].x]!=0;j++){
						if( demons[j].killed == false  && demons[j].x == demons[i].x ){
							demons[j].killed = true;
							Y[demons[j].y]--;
							X[demons[i].x]--;
						}
					}
				}
				else{
					for(j=1;j<=numpoints && demons[j].killed == false && demons[j].y == demons[i].y && Y[demons[i].y]!=0 ;j++){
						demons[j].killed = true;
						X[demons[j].x]--;
						Y[demons[i].y]--;
					}	
				}
		}
		printf("%d\n",count);

	}









	return 0;
}
 