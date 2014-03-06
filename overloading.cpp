#include<iostream>
using namespace std;

int add(int a, int b, int c){
	return a+b+c;
}

int add(int a, int b){
	return a+b;
}

int main(){
	cout << add(2,3);
	cout << add(2,4,5);
	return 0;
}
