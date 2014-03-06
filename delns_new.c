#include "stdio.h"


int main(){
	long int n = 0, i = 0,sol_count = 0,k = 0 , m = 0 , p = 0 , q = 0,r = 0,temp = 0;
	long int e[100010] = {0};
	long int o[100010] = {0};
	long int v[100010] = {0},t[100010] = {0};

	scanf("%ld",&n);

	for(i = 1;i<=n;i++){
		scanf("%ld",&e[i]);
		o[e[i]]++;
	}

	for(i = n;i>0;){
		
		if(o[e[i]] == 1){
			v[sol_count] = i;
			t[sol_count++] = 1;
			o[e[i]]--;
			i--;
		}
		else{
			for(k = i-1;e[k] != e[i] && k>0;k--);
				
			t[sol_count] = i - k;
			temp = i - k;

			o[e[i]]--;
			
			m = k;
			
			while(e[m] == e[i] && m>0 && o[e[i]] > 0){	
				m = m - t[sol_count];
				o[e[i]]--;
				p++;
			}

			m = m + t[sol_count];
			v[sol_count++] = m;

			k = m;

			for(q = m;q<=i-temp && q>0;q = q + temp){
				for(r = q+1;r < q+temp && r>0;r++)
					e[k++] = e[r];
			}


			i = k - 1;


		}

	}

	printf("%ld\n",sol_count);
	for(i=0;i<sol_count;i++){
		printf("%ld %ld\n",v[i],t[i]);
	}

	return 0;

}