// Start

// Take in the value of 'n' and the required value of sum 'm'

// Take in all the values for the banknotes in array 'd[]'

// For i = 1 and i < (2^n)

//     sum = 0

//     For j = 0 and j < n

//         if jth bit of i is set

//             sum = sum + d[j]

//     if sum equals m

//         print Yes and return

// Print No and return


#include "iostream"
using namespace std;

int main(){
	int n,m,i,j,temp,sum;
	int d[20];

	cin >> n;
	cin >> m;

	temp = n;
	
	while(temp)
		cin << d[n-temp--];

	for(i=0;i<pow(2,n);i++){
		sum = 0;
		for(j=0;j<n;j++){
			if(i && 1<<j){
				sum = sum + d[j];
			}
		}
	}




	return 0;
}