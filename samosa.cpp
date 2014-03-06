#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


int main(){	
	int rounds = 0,num_boxes = 0,i,num_bands,count = 0 ;
	long int t,r1,r2;
	std::ios_base::sync_with_stdio(false);


	vector<long int> boxes;
	vector< vector <double> > bands(4,vector<double>(2,0));

	cin >> rounds;
	

	while(rounds--){
	cin >> num_boxes;

	boxes.resize(num_boxes);

	for(i=0;i<num_boxes;i++){
		cin >> t;
		boxes[i] = 4*t;
	}

	sort(boxes.begin(),boxes.end());

	cin >> num_bands;

	bands.resize(num_bands);

	for(i=0;i<num_bands;i++){
		cin >> r1 >> r2; 
		bands[i][0] = (double)2 * r1 * 22/7;
		bands[i][1] = (double)2 * r2 * 22/7;
	}



	for(i=0;i<num_boxes;i++){

		for(int j = 0;j<num_bands;j++){
			if(boxes[i] >= bands[j][0] && boxes[i] <= bands[j][1]){
				count++;
				bands[j][0] = 0;
				bands[j][1] = 0;
				break;

			}
		}
	}



	cout <<count<<"\n";
	count = 0;

	}
	return 0;
}