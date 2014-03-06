#include "iostream"
#include "vector"
using namespace std;

void printvector(vector<int> a){
	for(int i=0;i<a.size();i++)
		cout << a[i];
};






vector <int> multiply(vector<int> a,int k){
	int carry = 0,temp,i;
	vector <int> ans(a.size(),0);



	for(i=0;i<a.size();i++){
		temp = a[i] * k + carry;
		ans[i] = temp%10;
		carry = temp/10;
	}


	printvector(ans);

	while(carry){
		ans.push_back(carry%10);
		carry = carry/10;
	}

	return ans;
}




int main(){
	int a[] = {2,4,9,3};
	vector <int> k(a,a+4);

	printvector(multiply(k,9));

	return 0;

}
