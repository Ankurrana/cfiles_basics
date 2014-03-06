#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#define get getchar_unlocked


inline int scan()
{
int n=0,s=1;
char p=get();
if(p=='-') s=-1;
while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
if(p=='-') s=-1,p=get();
while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
return n*s;
}

inline long int scan2(){
long int n=0,s=1;
char p=get();
if(p=='-') s=-1;
while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
if(p=='-') s=-1,p=get();
while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
return n*s;
}

// void selection_sort(long int a[],int SIZE){
// 	int pass,i,hold;
//  	for(pass = 1; pass <= (SIZE-1); pass++){
//         for(i = 0; i <= (SIZE-2); i++){
//             if(a[i] > a[i + 1])
//                {
//                     hold = a[i];
//                     a[i] = a[i + 1];
//                     a[i + 1] = hold;
//          		}
// 		}
// 	}
// }

// void quick_sort(long int arr[],long int low,long int high)
// {
//  long int pivot,j,temp,i;
//  if(low<high)
//  {
//   pivot = low;
//   i = low;
//   j = high;
 
//   while(i<j)
//   {
//    while((arr[i]<=arr[pivot])&&(i<high))
//    {
//     i++;
//    }
 
//    while(arr[j]>arr[pivot])
//    {
//     j--;
//    }
 
//    if(i<j)
//    {
//     temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
//    }
//   }
 
//   temp=arr[pivot];
//   arr[pivot]=arr[j];
//   arr[j]=temp;
//   quick_sort(arr,low,j-1);
//   quick_sort(arr,j+1,high);
//  }
// }


void quick_sort(long int *arr, int elements) {

  #define  MAX_LEVELS  300

  long int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R, swap ;

  beg[0]=0; end[0]=elements;
  while (i>=0) {
    L=beg[i]; R=end[i]-1;
    if (L<R) {
      piv=arr[L];
      while (L<R) {
        while (arr[R]>=piv && L<R) R--; if (L<R) arr[L++]=arr[R];
        while (arr[L]<=piv && L<R) L++; if (L<R) arr[R--]=arr[L]; }
      arr[L]=piv; beg[i+1]=L+1; end[i+1]=end[i]; end[i++]=L;
      if (end[i]-beg[i]>end[i-1]-beg[i-1]) {
        swap=beg[i]; beg[i]=beg[i-1]; beg[i-1]=swap;
        swap=end[i]; end[i]=end[i-1]; end[i-1]=swap; }}
    else {
      i--; }}}

int main(){
	char arr[120];
	int rounds=0,num_bottles=0;
	long int i=0,j=0;
	int rooms_total=0,rooms_visited=0;
	int visits[101] = {0};
	long long int sum = 0;
	long int bottle_volume[101] = {0},litres = 0;
	int temp_room_no = 0;


	// scanf("%d",&rounds);
	rounds = scan();

	while(rounds--){
		
		sum = 0;

		// scanf("%d",&rooms_total);
		// scanf("%d",&rooms_visited);
		// fastRead_int(rooms_total);
		// fastRead_int(rooms_visited);

		rooms_total = scan();
		rooms_visited = scan();


		for(i=0;i<101;i++){
			visits[i] = 0;
			bottle_volume[i] = 0;
		}

		for(i=0;i<rooms_visited;i++){
			// scanf("%d",&temp_room_no);
			temp_room_no = scan();
			visits[temp_room_no]++;
		}
		

		for(j=0;j<rooms_total;j++){			
			// scanf("%d",&num_bottles);
			num_bottles = scan();
			for(i=0;i<num_bottles;i++){
				litres = scan2();
				// scanf("%ld",&litres);
				bottle_volume[i] = litres;
			}

			// quick_sort(bottle_volume,0,num_bottles-1);
			quick_sort(&bottle_volume[0],num_bottles);

			for(i=num_bottles-1;i>=num_bottles - visits[j] ;i--){
				if(i>=0)	
					sum = sum + bottle_volume[i];
				else
					break;

			}
			
		}

		printf("%lld\n",sum);

	}
	




	return 0;
}