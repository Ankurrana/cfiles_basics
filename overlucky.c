#include "stdio.h"
#include "math.h"

#define get getchar_unlocked

inline long long int scan2(){
	long long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}



inline int isoverlucky(long long int k){
	int n;
	while(k>0){
		n = k%10;
		if(n == 7 || n == 4)
			return 1;
		k = k/10;
	}

	return 0;
}

int main(){
	long long int n,i,j,num,count = 0;
	n = scan2();
	


	for(i=0;i<n;i++){

		num = scan2();
		count = 0;
		j = 1;

		while(j < sqrt(num)){
	        if(num%j==0) {
	        		if(isoverlucky(j)){
	        			count++;
	        		}
	                  
	        		if(isoverlucky(num/j)){
	        			count++;

	        		}
	        }

	        j++;
	    }
	   
	   	if(j*j == num && isoverlucky(j)){
	   		
	   		count += 2;

	   	}

		
		printf("%lld\n",count);
	}


	return 0;

}