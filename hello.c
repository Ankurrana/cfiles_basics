
#include "stdio.h"

int main(){
	int rounds,c_no_of_calls,p_months,no_of_plans;
	double c_monthly_call_rate,p_call_rate,p_charge_for_one_month,c_total_charge;
	double p_total_charge,least_charge;
	int best_plan_number = 0,i;
	scanf("%d",&rounds);

	while(rounds--){	
		scanf("%lf%d%d",&c_monthly_call_rate,&c_no_of_calls,&no_of_plans);
		c_total_charge = c_monthly_call_rate * c_no_of_calls;

		least_charge = c_total_charge;


		for(i=0;i<no_of_plans;i++){
			
			scanf("%d%lf%lf",&p_months,&p_call_rate,&p_charge_for_one_month);
			p_charge_for_one_month = (double)p_charge_for_one_month/p_months;

			p_total_charge = (double)(p_charge_for_one_month + (double)p_call_rate * c_no_of_calls);

			if(p_total_charge < least_charge){
				best_plan_number = i+1;
				least_charge = p_total_charge;
			}
		}

		p_total_charge = 0;
		least_charge = c_total_charge;
		printf("%d\n",best_plan_number);
		best_plan_number = 0;
	}

	return 0;
}