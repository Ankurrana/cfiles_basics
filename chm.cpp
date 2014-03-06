#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"
#include "string"
#include "cstring"

	
using namespace std;

//The large numbers will be represented as strings


string mult(string a,int k){
	string b;
	int carry = 0,temp = 0,i;
	int size = a.size();

	for(i = size-1;i>=0;i--){
		temp = (int)(a[i] - 48)*k + carry;
		a[i] = (char)temp%10;
		carry = temp/10; 
	}

	while(carry){
		a = char(carry%10) + a;
		carry =  carry/10;
	}


	return a;
}







int main(){
	string a;
	cin >> a;

	cout << '10' - 28;
	return 0;
}