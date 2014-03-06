#include "stdio.h"

long int max(long int a,long int b,long int c){
    return a>b?(a>c?a:c):(b>c?b:c);
}


int main(){    
    long int n1,n2,n3,i;
    long int a[60000],b[60000],c[60000];
    scanf("%ld%ld%ld",&n1,&n2,&n3);
    
    for(i=0;i<n1;i++)
        scanf("%ld",&a[i]);;
    for(i=0;i<n2;i++)
        scanf("%ld",&b[i]);
    for(i=0;i<n3;i++)
        scanf("%ld",&c[i]);

    
    

    return 0;
}
