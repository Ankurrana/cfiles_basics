#include "iostream"
#include "stdio.h"

using namespace std;

long int solutions[200002];
long int solution_count = 0;



struct element{
	long int num;
	long int pos;
} e[100001];

struct solution{
	long int v;
	long int t;
} sol[100001];


long int sol_count = 0;


int main(){
	long int i,n,j,k = 0;
	long int occurances[100002];
	long int jump = 1,temp_count = 0,temp_t = 0,s = 0;
	element current_e;
	scanf("%ld",&n);

	
	for(i=0;i<n;i++){
		scanf("%ld",&e[i].num);   //The actual data
		e[i].pos = i+1;
		occurances[e[i].num]++;   //The occurances of each of the actual data
	}

	for(i=n-1;i>=0;){
		temp_count = 0;
		jump = 1;
		current_e = e[i];
		

		if(occurances[current_e.num] == 1){
			sol[sol_count].v = current_e.pos;
			sol[sol_count++].t = 1;
			occurances[e[i].num]--;   //  it will be set to zero;
			i--;
		}	
 		else {

		
 		//A system to find t , from the first two occurances of the number
		
		if(occurances[current_e.num] >= 2){			
			for(k=i-1;k>=0;k--){
				if(e[k].num == current_e.num){
					sol[sol_count].t = e[i].pos - e[k].pos;  //or i-k;
					temp_t = sol[sol_count].t;
					break;
				}
			}

			occurances[e[i].num] -= 1;

		}	

		

		for(s=k;current_e.num == e[s].num && s>=0 && occurances[e[i].num];s = s-temp_t)	
				occurances[e[i].num]--;
							
		s = s + temp_t;
		sol[sol_count++].v = e[s].pos;

		 	
		// s++;

		// for(; s <= i-1 ; s++ ){
		// 	temp_count++;
		// 	if(temp_count%temp_t!= 0){
		// 		e[s].pos -= jump;
		// 		e[s-jump] = e[s];
		// 	}
		// 	else
		// 		jump++;

		// }

		

		k = s;

		for(s=s;s<=i;s = s+temp_t){
			for(j=s+1;j<s+temp_t;s++){
				e[k].num = e[j].num;
				e[k].pos = k + 1;
				k++;
			}
		}


		i = k-1;


		
			//i = i - jump;
			//jump = 1;   //added afterwards
		}
	
	}


	//Just print the solution structure here 


	printf("%ld\n",sol_count);
	
	for(i=0;i<sol_count;i++){
		printf("%ld %ld\n",sol[i].v,sol[i].t);
	}

	return 0;
}