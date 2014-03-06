// defacing score. 

//i'll definitely use vectors to score the 
#include "iostream"
#include "vector"
#include "string"




int main(){
	short int a[] = {2,1,3,5,1,4};
	vector<short int> v = (a,a+6);
	int i;
	for(i=0;i<6;i++){
		cout >> v[i];
	}

	return 0;
}	