#include "stdio.h"

/* Priority Job First Without Premption  */

int global_time = 0;
int n;

struct P{
	int burst_time;
	int arrival_time;
	int is_executed;
	int start_time;
	int wait;
	int priority;
}Processes[20];


int extractmin(){
	int i;
	int min_p_id = 0;


	for(i=1;i<=n;i++){
		if((Processes[i].is_executed == 0) && (Processes[i].priority < Processes[min_p_id].priority) && (Processes[i].arrival_time <= global_time)) 
			min_p_id = 	i;
	}

	return min_p_id;
}



void ticker(){
	int p_id,i;
	int t_time = 0;
	int processes_executed = 0;
	
	while(processes_executed < n){
		p_id = extractmin();

		if(p_id == 0){
			global_time++;
			continue;
		}


		printf("Executing Process %d\n",p_id);  // This is the total Execution
		Processes[p_id].is_executed = 1;
		Processes[p_id].start_time = global_time;
		processes_executed++;
		global_time += Processes[p_id].burst_time; 
	}

}


void waiting_time(){
	int i;
	int total_waiting_time = 0;
	printf("Process |\tWaiting time\n");
	for(i=1;i<=n;i++){
		Processes[i].wait = Processes[i].start_time - Processes[i].arrival_time;
		total_waiting_time += Processes[i].wait;
		printf("%d\t|\t%d\n",i,Processes[i].wait);
	}

	printf("Total\t%d\n",total_waiting_time);
	printf("Average::%f",(float)((float)total_waiting_time/n));
}




int main(){
	int i;
	printf("Enter the Number of Processes::");
	scanf("%d",&n);
	printf("Enter %d lines with three integers each \nrepresenting arrival and burst time and priority of each Process\n",n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&Processes[i].arrival_time);
		scanf("%d",&Processes[i].burst_time);
		scanf("%d",&Processes[i].priority);
		Processes[i].is_executed = 0;
	}

	Processes[0].burst_time = 1000;
	Processes[0].arrival_time = 1000;
	Processes[0].is_executed = 0;

	ticker();
	waiting_time();
	return 0;
}