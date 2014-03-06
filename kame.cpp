
#include <cstdio>
#include "iostream"
#include "map"
using namespace std;
 
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

struct  points
{
	long long int x,y;
	bool killed;
} demons[1010];

long int rounds = 0,i = 0,numpoints = 0,x,y,j;
map <long long int, int >X;
map <long long int, int >Y;



void mapdetails(){
	int i = 0,j = 0;
	for(i=0;i<=7;i++,j++){
			cout << "X["<< i << "]:" << X[i] << "\n";
			cout <<  "Y[" << j << "]:" << Y[j] << "\n" ;
		}
}


int main(){
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


		/*  X and Y initial details   */

	



		//...................................................\\

		for(i=1;i<=numpoints;i++){
				
				if(demons[i].killed == false){

					cout << "Demon Killed with coordinates:: (" <<demons[i].x<<"," << demons[i].y << ")";


					count++;
					if( X[demons[i].x] >= Y[demons[i].y]){

					for(j=1; j<=numpoints;j++){
							
							if( (demons[j].x == demons[i].x) && demons[j].killed == false && X[demons[j].x]+1>0){
								demons[j].killed = true;
								Y[demons[j].y]--;
								X[demons[j].x]--;
							}

						}
					}
					else{
		
						for(j=1; j<=numpoints;j++){
							
							if( (demons[j].y == demons[i].y) && demons[j].killed == false && Y[demons[j].y]+1>0){
								demons[j].killed = true;
								X[demons[j].x]--;
								Y[demons[j].y]--;
							}

						}

					}



				}
		}
		printf("%d\n",count);

	}









	return 0;
}
 