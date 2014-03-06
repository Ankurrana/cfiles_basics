#include "iostream"
using namespace std;

int fact(int a){
	//if(a == 1)	
	//	return 1;
	//return a*fact(a-1);

	return (a==1)?1:a*fact(a-1); 
		
}

int main(){
	int a;
	cout << "Enter the number you want to find the factorial of\n";
	cin >> a;	
	cout << "\n" << fact(a);
	return 0;
}
