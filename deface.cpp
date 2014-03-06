#include "iostream"
#include "vector"
using namespace std;


int cover[10][10]={
	{0, 8, -1}, // for 0
	{0, 1, 3, 4, 7, 8, 9, -1}, // for 1
	{2, 8, -1}, // for 2
	{3, 8, 9, -1}, // for 3
	{4, 8, 9, -1}, // for 4
	{5, 6, 8, 9, -1}, // for 5
	{6, 8, -1}, // for 6
	{0, 3, 7, 8, 9,-1}, // for 7
	{8, -1}, // for 8
	{8, 9, -1} // for 9
};


void printvector(vector<int> a){
	int i;
	for(i=0;i<a.size();i++)
		cout << a[i];
	cout << "\n";
}

int out_max(int a){
	switch(a){
		case 0:
		case 2:
		case 6:
		case 8:
			return 8;
		default:
			return 9;
	}
};

int max_lesser_than_equal_to(int n,int limit){
	int i;
	for(i=0;cover[n][i]!= -1;i++){
		if(cover[n][i] > limit)
				break;
	}
		if(i!=0)
			return cover[n][i-1];
		else
			return n;

}

int one_lesser_than_maximum(int n,int limit){
	if(n == 10){
		return limit-1;
	}


	int i;
	for(i=0;cover[n][i]!= -1;i++){
		if(cover[n][i] > limit)
				break;
	}

	if(!(i < 1))
		return cover[n][i-2];
	return n;
}




vector<int> convert(vector<int> score,vector<int>max_score){
	//First these are equalized
	vector<int> final_score(max_score.size(),0);
	int diff = max_score.size() - score.size();
	int i = 0;
	int carry = 0;
	int z = diff;
	
	while(diff--){		
		final_score[i] = max_score[i];
		score.insert(score.begin(),10);
		i++;
	}


	

	for(;i<max_score.size() && !carry;i++){
			final_score[i] = max_lesser_than_equal_to(score[i],max_score[i]);
	if(final_score[i] < max_score[i])
		carry = 1;
		

		if(final_score[i] > max_score[i]) 
		{
			final_score[i-1] = one_lesser_than_maximum(score[i-1],max_score[i-1]);
			carry = 1;
			i--;
		}

	}

	for(;i<max_score.size();i++){
		final_score[i] = out_max(score[i]);
	}

	for(i=0;i<z;i++){
		if(final_score[0] == 0)
			final_score.erase(final_score.begin());
		else
			break;
		
	}
	

	return final_score;

}




int main(){
	int i;
	
	string a;
	string b;
	int rounds;
	vector<int> m;
	vector<int> s;
	cin >> rounds;
	int k = rounds;
	vector< vector<int> > answers;
	char c;

	
	
	while(k--){
		cin >> a;
		cin >> b;

		s.resize(a.size());
		m.resize(b.size());


		 for(i=0;i<a.size();i++)
		 		s[i] = a[i] - '0';
			

		 for(i=0;i<b.size();i++)
		 		m[i]= b[i] - '0';

		 	
		

		answers.push_back(convert(s,m));
		s.clear();
		m.clear();	
	}

	for(i=0;i<answers.size();i++){
		printvector(answers[i]);
	}

	return 0;
}