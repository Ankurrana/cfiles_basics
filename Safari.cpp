#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;


/*

n safari cars (0<=n<=50)
m passengers in the museum [0,5000]
q passengers at the park gate [0,100]
p each ride time [0,100]
r wandering passenger added to q;
k jurassic park is open for

*/


//seems simple
// N test cases [0,100]

it can be easily done in C, cant it! yes~!

int main(){
	long int total_time,current_time;
	int m_wandering_time,p_wandering_time,free_safari_cars,m_passengers,p_passengers_waiting,j;
	int N,passengers_riding;
	queue<int> passengers_time_count;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&t_safari_cars);
		scanf("%d",&m_passengers);
		scanf("%d",&p_passengers_waiting);
		scanf("%d",&p_wandering_time);
		scanf("%d",&m_wandering_time);
		scanf("%ld",&total_time);
		free_safari_cars = t_safari_cars;
		
		for(current_time=1 ; current_time <= total_time ; current_time++ ) {
			// second start::
			
			if(current_time%m_wandering_time == 0 && m_passengers){
				m_passengers--;
				p_passengers_waiting++;
			}

			
			// Past Second::
			for(j=0;j<passengers_riding;j++){
				passengers_time_count[j]++;
			}

			for(j=0;j<free_safari_cars && j<p_passengers_waiting;j++){
				p_passengers_waiting--;
				free_safari_cars--;
				passengers_time_count.push(0);
			}

			while(passengers_time_count.front() > p_wandering_time){
				passengers_time_count.pop();
				free_safari_cars++;
				passengers_riding--;
			}

		}
	}

	return 0;
}