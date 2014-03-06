#include <iostream>
#include <new>
using namespace std;

struct person {
	string name;
	int age;
	
};


int main ()
{	
  person ankur;
	
	ankur.name = "Ankur rana";
	ankur.age = 10;

	cout << ankur.name;
  return 0;
}
