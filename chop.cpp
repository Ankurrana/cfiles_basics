    /*----------------------------------------
    -- Author - Arpit Kumar Singh ------------
    -- Dated - Sun Jul 21 22:06:46 IST 2013 --
    ------------------------------------------*/
    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<vector>
    #define mod(a) ((a)<0)?-(a):a
    #define getcx getchar_unlocked
    using namespace std;
    inline void inp( int &n )//fast input function
    {
    n=0;
    int ch=getcx();
    int sign=1;
    while( ch < '0' || ch > '9' )
    {if(ch=='-')sign=-1; ch=getcx();}
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
    }
    inline void fastWrite(int a)
    {
    register char c;
    char snum[20];
    int i=0;
    do
    {
    snum[i++]=a%10+48;
    a=a/10;
    }while(a!=0);
    i=i-1;
    while(i>=0)
    putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
    }
    vector<int>c;
    int main(int argc,char *argv[]){
    int i,n,d,a;
    cin>>n>>d;
    for(i=0;i<n;i++){
    inp(a);
    c.push_back(a);
    }
    sort(c.begin(),c.end());
    a=0;
    for(i=1;i<n;i++){
    if(c[i]-c[i-1]<=d){
    i++;
    a++;
    }
    }
    fastWrite(a);
    return 0;
    }
