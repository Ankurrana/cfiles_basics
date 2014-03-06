// KMP algorithm
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

/* 
	Knuth - morris - pratt algorithm
	String searching algorithm




*/


void preKMP(string pattern)
{
		int f[pattern.size()];
        int m = pattern.size(),k;
        f[0] = -1;
        int i;
        for (i = 1; i<m; i++)
        {
                k = f[i-1];
                while (k>=0)
                {
                        if (pattern[k]==pattern[i-1])
                                break;
                        else
                                k = f[k];
                }
                f[i] = k + 1;
        }

        for(i=0;i<m;i++){
        	cout << f[i] << " ";;
        }
}


int main(){

	cout << "abbaabsab\n";
	preKMP("abbaabsab");
	return 0;

}