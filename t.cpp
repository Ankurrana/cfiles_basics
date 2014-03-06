#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define gc getchar_unlocked

int table[100][100];
long int max_sum;
long int inter_sum;
int max_rows;


void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}









void a_thread_sum(int parent_sum,int current_row,int current_column){
	int k;

	inter_sum = parent_sum + table[current_row][current_column];
	k = inter_sum;
	if(current_row < max_rows){
		a_thread_sum(inter_sum,current_row+1,current_column);
		a_thread_sum(k,current_row+1,current_column+1);		
	}
	else if(inter_sum > max_sum)
			max_sum = inter_sum;

}





int main(){
	max_sum = 0;
	int max_rows_t = 3;
	int rounds;
	int i=0,j=0,t=0,s=0;
	scanf("%d",&rounds);
	long int max_sums[1000];
	char a[10];

	while(rounds--){
		//gets(a);

		scanint(max_rows_t);
		//scanf("%d",&max_rows_t);
		//max_rows_t = atoi(a);
		
		
		max_rows = max_rows_t - 1;

		for(s=0;s<max_rows_t;s++){
			for(j=0;j<s+1;j++){
				scanint(table[s][j]);
				//gets(a);
				//table[s][j] = atoi(a);
				//scanf("%hd",&table[s][j]);
			}	
		}

		a_thread_sum(0,0,0);
		max_sums[t++] = max_sum;
		max_sum = 0;

	}


	for(i=0;i<t;i++){
		printf("%ld\n",max_sums[i]);
	}

	return 0;
}