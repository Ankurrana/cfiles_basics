#include "iostream"
#include "string"
using namespace std;

int main(){
	int x,y;
	string j;
	string s;
	int rounds;
	int count = 0;
	cin >> rounds;

	while(rounds--){
		cin >> j;
		cin >> s;


		for(x=0;x<s.size();x++){
			for(y=0;y<j.size();y++){
				if(s[x] == j[y]){
					count++; 
					break;
				}
			}			
		}

		cout << count << "\n";
		count = 0;
	}	
		




	return 0;

	
}
