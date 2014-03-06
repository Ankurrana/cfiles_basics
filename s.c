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




int main(){
	long int t = 0,x = 0,y = 0,v = 0,f1 = 0,f2 =0,f3 = 0;
	t = scan2();


	while(t--){

  		v = scan2();
  		
  		while(v--){
	  		x = scan2();
	  		y = scan2();

	  		if(x == y)
	  			f1 = 1;
	  		else if(x < y)
	  			f2 = 1;
	  		else
	  			f3 = 1;
  		}

  		if(f1 || (f2 && f3))
  			printf("YES\n");
  		else
  			printf("NO\n");

  			f1 = 0;
  			f2 = 0; 
  			f3 = 0;	

  	}
	return 0;
}