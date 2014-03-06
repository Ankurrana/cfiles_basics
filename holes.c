#include "isotream"
#include "string"
using namespace std;

int num_holes(string a){
	int sum = 0;
	a = a.uppercase();
	for(i=0;i<a.size();i++){
		if(a[i] == "A" || a[i] == "Q" || a[i] == "D" || a[i] == "O" || a[i] == "P" || a[i] == "R")
			sum = sum + 1;
			break;
		else if(a[i] == "B")
			sum = sum + 2;
			break;
	}

	return sum;
}

int main(){
	int i;
	string a;
	cin >> i;

	while(i--){
		cin >> a;
		cout << num_holes(a); 
	}

	return 0;
}