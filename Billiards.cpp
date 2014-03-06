//Billiards.cpp
#include "iostream"
#include "stdlib.h"
#include "cstdio"
#include "cstdlib"
using namespace std;



void scanint(int &x)
{
register int c = gc();
x = 0;
for( ;(c < 48 || c > 57); c = gc())
;
for( ;c > 47 && c < 58; c = gc())
{
x = ( x << 1 ) + ( x << 3 ) + c - 48;
}
}




int main(){
	short int w;   
	int lead = 0;
	int rounds;
	int a,b;
	cin >> rounds;
	int c;
	
	while(rounds --){
		cin >> a >> b;
		c = a-b;
		if(abs(a-b) > lead){
			w = c>0?1:2;
			lead = abs(c);
		}
	}
	
	cout << w << lead;

	return 0;
}
