#include "stdio.h"
#define get getchar_unlocked

inline int scan2(){
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

int testcases,n = 4,e_bamboos[60],c_bamboos[60],diff[60],i;
long int sum = 0 ;



int all_even(){
	int even = 0,odd = 0,i;

	for(i=0;i<n;i++){
		if( abs(diff[i])% 2 != 0){
			odd = 1;
		}
		else{
			even = 1;
		}
	}

	if(even == 1 && odd ==1)
		return 2;
	if(even == 1)
		return 0;
	if(odd == 1)
		return 1;

}



int solve(){
	//First know the difference a each step;



	int reducer = n-2;
	int steps;
	



	if(sum%reducer!= 0)
		return -1;
	else{

		//first check if all are even or all are odd or some of them are even and odd

		steps = sum/reducer;

		switch(all_even()){
			case 2:
				return -1;
				break;
			case 1:  //case of odd
				if(steps%2!=0)
					return steps;
				else
					return -1;
			case 0:
				if(steps%2 == 0)
					return steps;
				else
					return -1;
			default:
				return -1;
				
		}

	}


}


int main(){
	int count = 0;
	testcases = scan2();
	while(testcases--){
		sum = 0;
		count = 0;

		n = scan2();
		for(i=0;i<n;i++)
			e_bamboos[i] = scan2();

		for(i=0;i<n;i++)
			c_bamboos[i] = scan2();

		for(i=0;i<n;i++){
			diff[i] = c_bamboos[i] - e_bamboos[i];
			if(diff[i]<0)
				count++;
			sum = sum + diff[i];
		}
		if(n==1){
			if(diff[0]>0)
				printf("-1\n");
			else
				printf("%d\n",abs(diff[0]));
		}
		else if(n==2){
			if(diff[0] + diff[1] == 0)
				printf("%d\n",abs(diff[0]));
			else
				printf("-1\n");
		}
		else if(count == 1){
			//The absolute value of all shoyuld be same
			
			int same = abs(diff[0]);
			for(i=1;i<n;i++){
				if(same != abs(diff[i]))
					break;
			}


			if(i == n)
				printf("%d\n",abs(diff[0]));
			else
				printf("-1\n");

		}
		else if(count>1)
			printf("-1\n");
		
		else{
			printf("%d\n",solve());
		}

	}	
	return 0;

}