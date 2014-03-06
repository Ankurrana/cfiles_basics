//Testing vectors
#include "iostream"
#include "vector"
using namespace std;

int main(){
	int i;
	vector<short int> ar(3,12);
	ar.push_back(10);
	ar.push_back(20);
	ar.insert(ar.begin()+3,7);

	cout << ar[-1] << "\n";
	for(i=0;i<ar.size();i++){
		cout << ar[i];
	}

	return 0;
}