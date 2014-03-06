#include "stdio.h"
#include "math.h"
#define get getchar_unlocked
#define ulong unsigned long long int;

inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}




int th_primes[168] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int b[1000000] = {0}; //0 means the number is prime
long int p_count = 0;
long int p[1000000]; //this actually contains the primes

int r[1000000] = {0};

int main(){
	long int i, size, m ,lower, upper, k,testcases = 0;
    double div;  
    long int diff;

    b[0]=1;
    b[1]=1;
    for(i=0; i < 168; i++){
             m=2*th_primes[i];  //they started from the second instance of the prime number which is not a prime like 2*5 = 10;
             while(m<1000000)
             {
                           b[m]=1;
                           m = m + th_primes[i];
             }
    }

    for(i=2; i<1000000; i++){
        if(b[i]==0)
           p[p_count++] = i;  
    }

   

    testcases = scan2();

    while(testcases--){
    	lower = scan2();
    	upper = scan2();
    	diff = upper-lower+1;

    	for(i=0;i<diff;i++)
    		r[i] = 0;//assuming all are primes!

    	if(lower == 1)
    		r[0] = 1; //indicating 1 is not a prime!

    	for(i=0; i<p_count; i++)
          {
                   if(upper>p[i])
                   {
                                 div = (double)(lower)/p[i]; //this line here resolves the 
                                 k=ceil(div);
                                 
                                 if(k==1)
                                     m=p[i]*2-lower;
                                 else
                                     m=p[i]*k-lower;
                                 while(m < diff)
                                 {
                                         r[m]=1;
                                         m+=p[i];
                                 }          
                   }
          }

          //Now the r[] represents the boolean array that defines which of these numbers in our range are prime of not!
          //Now i need to move to my own question !
          //i need to define an external function for this to be a good algo!
          // for(i=lower;i<=upper;i++)
          	// printf("%d %d\n",2,r[2]);
          	// printf("%d %d\n",3,r[3]);
          	// printf("%d %d\n",5,r[5]);
          	// printf("%d %d\n",11,r[11]);
          	// printf("%d %d\n",17,r[17]);
          	// printf("%d %d\n",12,r[12]);
          	// printf("%d %d\n",26,r[26]);

    }

return 0;
}





// int primes[10000];

// void Eratosthenes(int n)
// {
// int boolean[n-1];//boolean array holds 0 if the numbers is not prime

// int ctr,outctr,inctr,primeassm;
// for(ctr=0;ctr<n-1;ctr++)
// {
//     primes[ctr]=ctr+2;//start storing numbers from 2 onwars
//     boolean[ctr]=1;//assume all to be prime
// }
// for(outctr=0;outctr<n/2+1;outctr++)
// {
//     if(boolean[outctr]==1)
//     {
//     primeassm=primes[outctr];//perform primality check for indivusal numbers
//     for(inctr=outctr+1;inctr<n-1;inctr++)
//     if(primes[inctr]%primeassm==0)//if divisible set boolean to 0
//     boolean[inctr]=0;
//     }
// }
// printf("\nThe prime numbers till the given range are\n");
// for(ctr=0;ctr<n-1;ctr++)
// if(boolean[ctr]==1)//display the primes of prime numbers
// printf("%d\n",primes[ctr]);
// }

// int is_prime(){
// 	return 1;
// }


// int dohaveprimenumberoffactors(int n){
// 	int mul = 1;
// 	if(is_prime(n))
// 		return 1;
// 	int i,count = 0;

// 	for(i=0;primes[i]*primes[i] <= n;i++){
// 		while(n%primes[i] == 0)
// 			count++;
// 		if(!is_prime(count+1) || !is_prime(mul * (count+1)))
// 			return 0;
// 		else{
// 			mul *= (count+1);
// 			continue;
// 		}
// 	}
// 	if(!is_prime(mul))
// 		return 1;

// }


