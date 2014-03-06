#include "stdio.h"
int main(){
	float total_amount; 
	int widraw_amount;
	scanf("%d",&widraw_amount);
	scanf("%f",&total_amount);

	if(  (widraw_amount > (total_amount-0.5)) || (widraw_amount%5 != 0) ){
		printf("%f",total_amount);
	}
	else{
		total_amount = total_amount - (widraw_amount + 0.5);
		printf("%.2f",total_amount);
	}
	return 0;
}