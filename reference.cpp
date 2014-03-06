#include<iostream>
using namespace std;

void add(int *a,int *b){
	//This function stored the result in the variable a itself
	*a = *a + *b;
}

int main(){
	int x = 10;
	int y = 30;
	add(&x,&y);
	cout << x;
	return 0;


}
