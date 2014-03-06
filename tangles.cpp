//July lunch time
#include "iostream"
#include "string.h"
#include "algorithm"

using namespace std;



long long int for1(string a,string b){
int a_s[26],b_s[26],i=0;

long long int sum = 0;

for(i=0;i<26;i++){
	a_s[i] = 0;
	b_s[i] = 0;

}
for(i=0;a[i]!='\0';i++)
	a_s[(int)a[i]-97]++;

	
for(i=0;b[i]!='\0';i++)
	b_s[(int)b[i]-97]++;


for(i=0;i<26;i++){
	sum = sum + a_s[i]*b_s[i];
}

return sum;

}





int main(){
	int i;
	int rounds;	
	string a,b;
	long long int l;
	cin >> rounds;
	while(rounds--){
		cin >> a;
		cin >> b;
		cin >> l;

		cout << for1(a,b);
		for(i=0;i<l-1;i++)
			cout << " " << 10;
	}
	return 0;

}