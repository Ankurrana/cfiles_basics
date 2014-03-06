#include "iostream"
#include "vector"
#include "algorithm"
#include "stdio.h"

using namespace std;

// Every number is actually represented as a vector of short ints



void showvector(vector< short int > a){
    for(int i=0;i<a.size();i++)
        printf("%d",a[i]);
    printf("\n");
};


vector<short int> multiply(vector<short int> a ,int k){
    int i,carry = 0 ,temp;
    vector<short int>ans;
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

vector <short int> subtract(vector <short int> a,vector<short int> b){
    vector <short int> ans(a.size(),0);
    int sizea = a.size();
    int sizeb = b.size();
    int i,j;
    //First find the complement
    
    //Never allow b bigger than a;

    for(j=0;j<sizea;j++){
        if(a[i] > b[i])
            ans[i] = a[i] - b[i];
        else
            ans[i] = a[i] + 10 -b[i];
            a[i-1] -= 1; 
    }

    return ans;
}



int main(){
    int i;
    int b[] = {5,6,7};
    vector< short int > r(b,b+2);
    vector <short int> a[100];

    a[0] = r ;

    showvector( multiply(a[0],2));

    return 0;
}