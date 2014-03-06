#include "stdio.h"
#include "string.h"
#define get getchar_unlocked

inline int scan2(){
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

void quicksort(int x[],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}


int main(){
	int t;	
	int a[10001] = {0},nums[101]={0};
	int n = 0;
	int k = 0,i,temp=0;
	int maxfre = 0, element = 0;
	int p = -1;
	t = scan2();
	
	while(t--){

		memset(a,0,sizeof(a));
		memset(nums,0,sizeof(nums));

		n = scan2();
		p = -1;
		
		for(i=0;i<n;i++){
			temp = scan2();
			a[temp]++;
			nums[i]=temp;
		}

	

	quicksort(nums,0,n-1);
	
	k = 0;
	
	for(i=0;i<n;i++){
		if(p!=nums[i]){
			nums[k++] = nums[i];
			p = nums[i]; 
		}

	}



	for(i=0;i<k;i++){
		if(a[nums[i]] > maxfre){
			maxfre = a[nums[i]];
			element = nums[i];
		}
	}

	printf("%d %d\n",element,maxfre);



	}
	return 0;
}