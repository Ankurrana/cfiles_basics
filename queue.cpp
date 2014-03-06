// queue.cpp

#include "iostream"
#include "queue"
#include "stack"
#include "map"
using namespace std;

int main(){
	map <char,int> m;
	m['k'] = 345;
	m['a'] = 156;
	m['b'] = 2;
	m['z'] = 12;
	
	map<char,int>::iterator it;

	m.insert(pair<char,int>('s',34));
	
	pair<char,int> p('1',42);
	
	m.insert(p);
	

	it = m.find('a');

	m.erase(it,it+3);



	for(it = m.begin();it!=m.end();it++)
		cout << it->first << "=>"  <<  it->second <<endl;



	return 0;
}



for(i=1;i<=n;i++){
			if(a[i] == 1){
				if(temp){
					assistant[as++] = i;
					temp = 0;
				}
				else{
					chef[c++] = i;
					temp = 1;					
				}
			}
			
		}

		for(i=0;i<c;i++)
			printf("%d ",chef[i]);
		printf("\n");

		for(i=0;i<as;i++)
			printf("%d ",assistant[i]);


		printf("\n");

		as = 0;
		c = 0;
		for(i=0;i<1001;i++)
			a[i] = 1;