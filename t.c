    #include<stdio.h>
    #define BUF 4096
    char ibuf[BUF];
    int ipt = BUF;
    int readInt() {
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    }
    return n;
    }
    int main()
    {
    int flag=0;
    int arr[100002];
    int i,n;
    n=readInt();
    while(n>0)
    {
    flag=0;
    for(i=1;i<=n;i++)
    arr[i]=readInt();
    for(i=1;i<=n;i++)
    {
    if(arr[arr[i]]!=i)
    {
    flag=1;
    break;
    }}
    if(flag==0)
    printf("ambiguous\n");
    else
    printf("not ambiguous\n");
    n=readInt();
    }
    return 0;
    } 