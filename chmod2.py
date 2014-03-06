import sys
# import psyco
# psyco.full()

def main():
    resulto = [];
    main_a = [];
    # n_el = raw_input();
    n_el = sys.stdin.readline();
    # for x in range(0,n_el):
    # main_a.append(input());
     
    main_a = map(int, sys.stdin.readline().split())
    temp = 1;
     
    for x in xrange(int(n_el)):
        temp = temp * main_a[x];
        resulto.append(temp);
     
    nu_games = input();
    count = 0;
    while count < nu_games :
        a = map(int, sys.stdin.readline().split())
        # li = input();
        # ri = input();
        # mod = input();
        li = a[0];
        ri = a[1];
        mod = a[2];
         
        if(li > 1):
            ans = (resulto[ri-1]/resulto[li-2]);
        else:
            ans = resulto[ri-1];
         
        finalans = ans%mod;
        print(finalans);
        count+=1;

if __name__ == "__main__":
    sys.exit(main())