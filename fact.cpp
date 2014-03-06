#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<unsigned short int> multiply(vector<unsigned short int> a ,int k){
	int i,carry = 0 ,temp;
	vector<unsigned short int>ans;
	
	int size = a.size();

	for(i=0;i<size;i++){
		temp = a[size - i - 1]*k + carry;
		ans.push_back(temp%10);
		carry = temp/10;
	}

	while(carry>0){
		ans.push_back(carry%10);
		carry = carry/10;
	}

	reverse(ans.begin(),ans.end());

	return ans;
};


int main(){
	int i,j,k;
	vector<unsigned short int> h(1,1);
	cin >> j;
	

	int a[j];

	for(i=0;i<j;i++)
		cin >> a[i];


	for(k=0;k<j;k++){
		for(i=1;i<=a[k];i++){
			h = multiply(h,i);
		};

		for(i=0;i<h.size();i++){
			cout << h[i];
		}

		h.clear();
		h.push_back(1);
		cout << endl;
	}





	
	
	

	return 0;
}