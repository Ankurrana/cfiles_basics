#include "iostream"
using namespace std;

int main(){
	long int n,k,i=0,count;
	
	long int *nums;
	cin >> n ;
	cin >> k ;

	nums = new long int[n];

	cout << "n: " << n << "k :"<< k;

	for(i=0;i<n;i++){
		cin >> nums[i];
		if(nums[i]%k == 0)
			count++;
	}

	delete nums;

	cout << "Total:: " <<count;
	return 0;
}