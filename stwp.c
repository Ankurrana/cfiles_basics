#include "stdio.h"

/* Shortest Job With Premption  */

int global_time = 0;
int n;

struct P{
	int burst_time;
	int arrival_time;
	int is_executed;
	int start_time[20];
	int end_time[20];
	int wait;
	int k;
}Processes[20];


int extractmin(){
	int i;
	int min_p_id = 0;

	for(i=1;i<=n;i++){
		if((Processes[i].is_executed == 0) && (Processes[i].burst_time < Processes[min_p_id].burst_time) && (Processes[i].arrival_time <= global_time)) 
			min_p_id = 	i;
	}
	return min_p_id;
}



void ticker(){
	int p_id,i;
	int t_time = 0;
	int processes_executed = 0;
	int old_p_id = 0;

	while(processes_executed < n){
		p_id = extractmin();

		if(old_p_id!=p_id && p_id == 0){
			global_time++;
			Processes[old_p_id].end_time[Processes[old_p_id].k-1] = global_time-1;
			old_p_id = p_id;
			continue;
		}

		if(p_id != old_p_id && p_id != 0){
			printf("Executing Process %d\n",p_id);
			Processes[old_p_id].end_time[Processes[old_p_id].k-1] = global_time;
			Processes[p_id].start_time[Processes[p_id].k++] = global_time;
			old_p_id = p_id;
		}

		Processes[p_id].burst_time--;
		
		if(Processes[p_id].burst_time == 0){
			Processes[p_id].end_time[Processes[p_id].k-1] = global_time;
			Processes[p_id].is_executed = 1;
			processes_executed++;
		}



		global_time++; 
	}

	Processes[old_p_id].end_time[Processes[old_p_id].k-1] = global_time; 

}


void waiting_time(){
	int i,j;
	int total_waiting_time = 0;
	

	int start = 0;
	int end = 0;
	
	for(i=1;i<=n;i++){
		Processes[i].wait = 0;
		end = Processes[i].arrival_time;

		for(j=0;j<Processes[i].k;j++){
			start = Processes[i].start_time[j];
			Processes[i].wait += start - end;
			end = Processes[i].end_time[j]; 
		}

		// printf("Total waiting_time of process %d : %d\n",i,Processes[i].wait);
	}

	printf("________________________");
	printf("\n|Process |\tWaiting\t|");
	printf("\n________________________");
	for(i=1;i<=n;i++){
		printf("\n|%d\t|\t%d\t|",i,Processes[i].wait);
		total_waiting_time += Processes[i].wait;
	}
	printf("\n________________________");

	printf("\nTotal Waiting::%d\nAverage Waiting::%.2f",total_waiting_time,((float)total_waiting_time)/n    );
	printf("\n________________________");


	printf("\n#######Complete Sequence of Execution of the processes########");

	for(i=1;i<=n;i++){
		printf("\nProcess %d",i);

		for(j=0;j<Processes[i].k;j++){
			printf("\n%d\t%d",Processes[i].start_time[j],Processes[i].end_time[j]);
		}
	}

	// printf("Total\t%d\n",total_waiting_time);
	// printf("Average::%f",(float)((float)total_waiting_time/n));
}




int main(){
	int i;
	printf("Enter the Number of Processes::");
	scanf("%d",&n);
	printf("Enter %d lines with two integers each representing arrival\n and burst time,priority of each Process\n",n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&Processes[i].arrival_time);
		scanf("%d",&Processes[i].burst_time);
		Processes[i].is_executed = 0;
		Processes[i].k = 0;
	}

	Processes[0].burst_time = 1000;
	Processes[0].arrival_time = 1000;
	Processes[0].is_executed = 0;

	ticker();
	waiting_time();
	return 0;
}