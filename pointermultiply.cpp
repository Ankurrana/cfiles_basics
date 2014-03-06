#include<iostream>
using namespace std;

int main(){
	

	//This program shows that two pointers cannot be operated upon  by a ninary operator like "+" or "*"
	int a;
	int b;
	int *p,*q;
	p = &a;
	q = &b;
	*(++p) = 10;
	cout << *(p+q);   //Ivalid Line
	return 0;
}
