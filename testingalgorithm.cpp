#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int main(){
	int arra[] = {1,61,6,2,5,3,2,656,53,534,745,6,2,342,5,234,2,632,45,234,63,6,45,32,47,4,87,8,7684,6,3};
	vector<int> v(arra,arra + 31);
	int i=0;
	for(i=0;i<v.size();i++)
		cout << v[i] << endl;
	return 0;

}