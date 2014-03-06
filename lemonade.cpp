#include "iostream"
#include "vector"

using namespace std;



int loc_of_max( vector<int> a ){
	int pos = 0;
	for(int i=0;i<a.size();i++)
		if(a[i]>a[pos])
			pos = i ;
	return pos;
}

int main(){
	short unsigned int rounds;
	int i,temp_roomno;
	unsigned int rooms_total,rooms_visited;
	vector<int> order;
	vector< vector<int> > travelling;
	cin >> rounds;
	
	std::ios_base::sync_with_stdio(false);

	while(rounds--){
		cin >> rooms_total;

		travelling.resize(rooms_total);

		cin >> rooms_visited;

		order.resize(rooms_visited);

		for(i=0;i<rooms_visited;i++){
			cin >> temp_roomno;
			order.[i] = temp_roomno;
		}

		

		for(i=0;i<rooms_total;i++){
			int num_bottles,litres;
			cin >> num_bottles;

			
			for(i=0;i<num_bottles;i++){
				cin >> litres;
				travelling[i] = litres;
			}

			
		}


		long long int sum = 0;

		int loc ;
		
		for(i=0;i<rooms_visited;i++){
			loc = loc_of_max(travelling[order[i]]);
			sum = sum + travelling[order[i]][loc];
			travelling[order[i]][loc] = 0;
		}

		cout << sum << "\n";
		sum = 0;


		travelling.clear();
		order.clear();


	}

	





	return 0;
}