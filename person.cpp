#include "iostream.h"
using namespace std;

class person{
	public:
		string name;
		int age;
		person(string n,int a){
			name = n;
			age = a;
		};
		person(){
			name = "Ankur rana";
			age = 20;
		};
}