#include "iostream"
using namespace std;

int main(){
	long int n,k,i=0,count;
	
	long int *nums;
	cin << n ;
	cin << k ;

	nums = new long int[n];


	for(i=0;i<n;i++){
		scanf("%ld",&nums[i]);
		if(nums[i]%k == 0)
			count++;
	}

	printf("%ld",count);
	return 0;
}