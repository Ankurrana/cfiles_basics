#include "iostream"
#include "string"
#include "vector"

using namespace std;

 class Person{
 	string name;
 	public:
 		Person(string name){
 			this->name = name;
 		}
 		void sayhi(){
 			cout << "Hello," << name  <<  endl;
 		}
 		string get_name(){
 			return name;
 		}	
 };

 class Emp:public Person{
 		int i;
	public:
		Emp(int j,string name)
		:Person(name){
			i = j;
		}
		void set_i(int i){
			this->i = i;
		}

		int get_i(){
		 	return this->i;
		 }; 	
 };


void twice(int &i){
	i = 2*i;
}


int main(){
	// Emp ankur(12,"Ankur");

	// ankur.sayhi();
	//ankur.set_i(10);
	// cout << ankur.get_i() << endl;
	// cout << ankur.get_name();
	// int k = 10;
	// twice(k);
	// cout << k;

	int ar[] = {2,5,3,6,2,7};
	vector<int> a;
	vector<int>::iterator i;
	i = a.begin();

	// cout << a.size();

	// cout << a.find(3);

	for(int j = 0;j<100;j++){

		a.push_back(j*2);
		cout << a.size() << endl;
	}



	// while(i!=a.end()){
	// 	cout << *i << endl;
	// 	i++;
	// }

	return 0;

}