#include "iostream"
#include "string"
using namespace std;

int num_holes(string a){
	int i,sum = 0;
	
	for(i=0;i<a.size();i++){
		a[i] = toupper(a[i]);
		if(a[i] == 'A' || a[i] == 'Q' || a[i] == 'D' || a[i] == 'O' || a[i] == 'P' || a[i] == 'R')
			sum = sum + 1;
		else if(a[i] == 'B')
			sum = sum + 2;
	}

	return sum;
}

int main(){
	int i,j;
	string a;
	cin >> i;
	int k[i];
	j = i;

	while(i--){
		cin >> a;
		k[i] = num_holes(a); 
	}

	while(j--)
		cout << k[j] << endl;

	return 0;
}