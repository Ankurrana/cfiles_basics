#include "iostream"
#include "string"
#include "cstdio"

using namespace std;

int main(){
	string a[41],temp = "Begin";
	int rounds, turns,i = 0;
	scanf("%d",&rounds);
	while(rounds--){
		scanf("%d",&turns);
		
		for(i=0;i<turns;i++){
			// cin >> a[i];
			std::getline(std::cin,a[i]);
		}

		for(i=turns;i>=0;i--){

			cout << a[i] << endl;

			// if(a[i][0] == 'L'){
			// 	a[i].erase(0,5);
			// 	cout << temp << a[i] << endl;
			// 	temp = "Right";
			// }	
			// else{
			// 	a[i].erase(0,6);
			// 	cout << temp << a[i] << endl;
			// 	temp = "Left";
			// }

		}



	}	





	return 0;
}