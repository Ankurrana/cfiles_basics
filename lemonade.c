#include "stdio.h"


void selection_sort(long int a[],int SIZE){
	int pass,i,hold;
 	for(pass = 1; pass <= (SIZE-1); pass++){
        for(i = 0; i <= (SIZE-2); i++){
            if(a[i] > a[i + 1])
               {
                    hold = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = hold;
         		}
		}
	}
}




int main(){
	int rounds=0,num_bottles=0;
	long int i=0,j=0;
	int rooms_total=0,rooms_visited=0;
	int visits[101] = {0};
	long long int sum = 0;
	long int bottle_volume[101] = {0},litres = 0;
	int temp_room_no = 0;


	scanf("%d",&rounds);


	while(rounds--){
		
		sum = 0;

		scanf("%d",&rooms_total);
		scanf("%d",&rooms_visited);


		for(i=0;i<101;i++){
			visits[i] = 0;
			bottle_volume[i] = 0;
		}

		for(i=0;i<rooms_visited;i++){
			scanf("%d",&temp_room_no);
			visits[temp_room_no]++;
		}
		

		for(j=0;j<rooms_total;j++){			
			scanf("%d",&num_bottles);
			
			for(i=0;i<num_bottles;i++){
				scanf("%ld",&litres);
				bottle_volume[i] = litres;
			}

			selection_sort(bottle_volume,num_bottles);

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