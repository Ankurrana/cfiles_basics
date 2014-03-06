#include "stdio.h"
#define MAX 1000000

unsigned int nums_one[1000];
unsigned int nums_two[10000];
unsigned long int num_three[100000];
unsigned long int num_four[1000000];
unsigned short int i[4] = {0,0,0,0}; 


unsigned short int num_of_chars(num){
	unsigned short int count = 0;
	while(num/10 != 0 ){
		count++;
		num = num/10;
	};
	return (count+1);
};

void put_into_arrays(unsigned long int num){
	switch(num_of_chars(num)){
		case 1:
		case 2:
		case 3:
			nums_one[i[0]++] = num;
			break;
		case 4:
			nums_two[i[1]++] = num;
			break;
		case 5:
			num_three[i[2]++] = num;
			break;
		case 6:
			num_four[i[3]++] = num;
			break;		
	};
};

void partition(int arr[],int low,int high){
 
    int mid;
 
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
 
void mergeSort(int arr[],int low,int mid,int high){
 
    int i,m,k,l,temp[MAX];
 
    l=low;
    i=low;
    m=mid+1;
 
    while((l<=mid)&&(m<=high)){
 
         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }
 
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

void sort_all(){
	partition(nums_one,0,i[0]);
	partition(nums_two,0,i[1]);
	partition(num_three,0,i[2]);
	partition(num_four,0,i[3]);
}

void print_array()


void print_all(){

}




int main(){
	int merge[MAX];
	unsigned long int num;
	unsigned long int n_o_n;

	scanf("%ld",&n_o_n);

	while(n_o_n-- != 0){
		scanf("%ld",num);
		put_into_arrays(num);

	};

	sort_all();


	return 0;
}