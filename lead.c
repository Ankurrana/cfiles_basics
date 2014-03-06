    //#include "iostream"
    #include "stdio.h"
    #include "stdlib.h"
    //using namespace std;
     

    // int main(){
    // short int w;
    // int lead = 0;
    // long int rounds;


    // std::ios_base::sync_with_stdio(false);


    // cin >> rounds;

    // long long int a=0,b=0,at=0,bt=0,c=0;
    


    // while(rounds --){
    // cin >> a;
    // cin >> b;

    // a = a + at;
    // b = b + bt;
    // c = a-b;
    // if(abs(a-b) > lead){
    // w = c>0?1:2;
    // lead = abs(c);
    // }

    // at = a;
    // bt = b;

    // }
    // cout << w << " " <<lead << "\n";
     
    // return 0;
    // } 




    int main(){
        long long int a=0,b=0,at=0,bt=0,c=0;
        char w;
        int lead,rounds;

        scanf("%d",&rounds);
        while(rounds--){
            scanf("%lld",&a);
            scanf("%lld",&b);
            a = a + at;
            b = b + bt;
            c = a-b;
            if(abs(c) > lead){
                w = c>0?'1':'2';
                lead = abs(c);
            }
            at = a;
            bt = b; 
        }

        printf("%c %d",w,lead);

        return 0;

    }