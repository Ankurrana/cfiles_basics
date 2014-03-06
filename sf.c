    /*Small factorials*/
     
    #include<stdio.h>
     
    void fact( int);
    void print(void);
     
     int factorial[80];
     int length;
     
    int main()
    {
     int i,n,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    scanf("%d",&n);
    fact(n);
    print();
    }
    return 0;
    }
     
    void fact( int n)
    {
     int i,j,sum,temp;
    for(i=1;i<80;i++)
    factorial[i]=0;
    factorial[0]=1;
    length=1;
    for(i=2;i<=n;i++)
    {
    j=temp=0;
    while(j<length)
    {
    sum=temp+factorial[j]*i;
    factorial[j]=sum%100;
    j++;
    temp=sum/100;
    }
    while(temp>0)
    {
    factorial[j++]=temp%100;
    temp/=100;
    length++;
    }
    }
    }
     
    void print(void)
    {
     int i;
    printf("%d",factorial[length-1]);
    for(i=length-2;i>=0;i--)
    {
    if(factorial[i]>=10)
    printf("%d",factorial[i]);
    else
    printf("0%d",factorial[i]);
    }
    printf("\n");
    } 