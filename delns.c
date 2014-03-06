// #include "iostream"
#include "stdio.h"
#define get getchar_unlocked




// using namespace std;

long int solutions[100050];
long int solution_count = 0;




inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}






struct solution{
	long int v;
	long int t;
} sol[100001];


long int sol_count = 0;


int main(){
	long int i=0,n=0,j=0,k=0 , t = 0;
	long int e[100002] = {0};
	long int occurances[100002] = {0};
	long int jump = 1,temp_count = 0,temp_t = 1,s = 0;
	//scanf("%ld",&n);
	n = scan2();
	


	for(i=0;i<n;i++){
		//scanf("%ld",&e[i].num);   //The actual data
		e[i] = scan2();
		// e[i].pos = i+1;
		// e[i] = rand();
		occurances[e[i]]++;   //The occurances of each of the actual data
	}

	for(i=n;i>0;i--){
		temp_count = 0;
		jump = 1;
		
		

		if(occurances[e[i]] == 1){
			sol[sol_count].v =  i+1;  //e[i].pos
			sol[sol_count++].t = 1;
			occurances[e[i]]--;   //  it will be set to zero;
			continue;
		}	
 		else {

		
 		//A system to find t , from the first two occurances of the number
		
		if(occurances[e[i]] >= 2){			
			for(k=i-1;k>=0;k--){
				if(e[k] == e[i]){
					sol[sol_count].t = i-k;//e[i].pos - e[k].pos;  //or i-k;
					temp_t = i-k;
					break;
				}
			}

			occurances[e[i]]--;

		}	

		

		for(s = k; e[i]== e[s] && s>=0 && (occurances[e[i]] != 0) ;s = s-temp_t)	
				occurances[e[i]]--;
		


		s = s + temp_t;
		sol[sol_count++].v = s+1 ;//e[s].pos;

		 	
		// s++;
		
		// for(; s <= i-1 ; s++ ){
		// 	temp_count++;
		// 	if( temp_count % temp_t == 0){
		// 		//e[s].pos -= jump;
		// 		jump++;
		// 		// e[s-jump] = e[s];
		// 		temp_count = 0 ;
		// 	}
		// 	else
		// 		e[s-jump] = e[s];
		// 		// jump++;
		// }

		k = s;

		for(; s < i-temp_t ; s = s+temp_t){
			for(j=s+1;j<s+temp_t;j++){
				e[k++] = e[j];
			}
		}

		
			i = k;
			   
		}
	
	}


	//Just print the solution structure here 


	printf("%ld\n",sol_count);
	
	for(i=0;i<sol_count;i++){
		printf("%ld %ld\n",sol[i].v,sol[i].t);
	}


	return 0;
}