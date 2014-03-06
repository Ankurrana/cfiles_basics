#include "iostream"
#define PI 3.142856
using namespace std;

int main(){
	double radius;
	double area;
	cout << "A simple program to determine the area of a circle\n";
	start:
	cout << "Enter radius(float)\n";
	cin >> radius;
	if(radius>0)
		cout << radius*radius*PI;
	else{
		cout << "Please Enter a Valid Positive integer as the radius of the cirlce";	
		goto start; 	
	}
	return 0;

	}
