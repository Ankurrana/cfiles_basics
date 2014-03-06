#include<iostream>
using namespace std;

int main(){
	
	int a[5] = {1,2,3,4,5};
	int *p;
	//Extremely important , the array name itself is a pointer. So you can execute the next instruction without an error.
	p = a;
	cout << p;
	return 0;
}
