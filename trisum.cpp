#include "stdio.h"

short int table[4][4] = {{1,0,0,0},{1,2,0,0},{4,1,2,0},{2,3,1,1}};
long int max_sum;
long int inter_sum;
int max_rows;

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
	max_rows = 3;
	int rounds;
	int i=0,j=0,t=0,s=0;
	scanf("%d",&rounds);
	long int max_sums[1000];


	while(rounds--){
		scanf("%d",&max_rows);
		t = max_rows;

		for(s=0;s<max_rows;s++){
			for(j=0;j<s+1;j++){
				//scanf("%d",&table[s][j])
				printf("* ");
			}
			printf("\n");
		}




	}



	//a_thread_sum(0,0,0);

	// printf("%ld",max_sum);
	return 0;
}