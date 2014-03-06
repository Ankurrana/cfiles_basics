#include <stdio.h>
#include <malloc.h>
#include "math.h"



void sieve( long int *,  long int);

int main()
{
	long int *a, n,i,*primes,p_count = 0,lower,upper,diff,*r,k,m,div,testcases;

	a = (long int *)malloc(2000010 * sizeof( long int));
	primes = (long int *)malloc(2000010 * sizeof( long int));
	r =( long int *)malloc(2000010 * sizeof( long int));

	int count_testing = 0;

	sieve(a,1000000);

	for(i=2; i<=1000000; i++){
		if(a[i] == 1)
			primes[p_count++] = i;
	}

	// printf("These are primes :: \n");
	// for(i=0;i<50;i++)
	// 	printf("%ld\n",primes[i]);


	scanf("%ld",&testcases);

	while(testcases--){
		scanf("%ld%ld",&lower,&upper);
		diff = upper - lower + 1;

		for(i=0;i<diff;i++)
			r[i] = 1; //everything is considered to be prime

		if(lower == 1)
			r[0] = 0;  // 0 means the number is not a prime;


		for(i=0; i<p_count; i++)
          {
                   if(upper>primes[i])
                   {
                                 k = ceil((double)lower/(double)primes[i]);
                                 
                                 if(k==1)
                                     m=primes[i]*2-lower;
                                 else
                                     m=primes[i]*k-lower;
                                 while(m < diff)
                                 {
                                         r[m]=0;
                                         m+=primes[i];

                                 }       
                                    
                   }
          }

          // printf("\nThese are the primes in the specified range");
          
          // for(i=0;i<50;i++){
          // 	printf("%ld = %ld",lower+i,r[i]);
          // }


          for(i=0;i<diff;i++){
          	if(r[i] == 1){          		
          		printf("%ld\n",lower+i);
			}          	
          	
          }

          // printf(" total primes in range %ld and %ld are %d",lower,upper,count_testing);

          printf("\n");


	}




}

void sieve( long int *a, long int n){
	 long int i, j;

	for(i=2; i<=n; i++)
		a[i] = 1;  //assuming 1 for prime, initially all are considered prime
	for(i=2; i<=n; i++){
		if(a[i] == 1){
			for(j=i; (i*j)<=n; j++)
				a[(i*j)] = 0;
		}
	}
}