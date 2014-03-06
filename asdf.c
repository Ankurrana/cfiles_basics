#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define T(x) ((x << 1) + (x << 3) + (str[k] - 48))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
 
int MOD;
int n = 0, q = 0, ye = 0, ar[101000][25];
char str[10000100], str2[3000000], str3[15];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
 
long long int bigmod(long long int x, int n){
    long long int res = 1;
 
    while (n){
        if (n & 1){
            res = res * x;
            if (res > MOD) res = (res % MOD);
        }
        x = (x * x);
        if (x > MOD) x = (x % MOD);
        n >>= 1;
    }
 
     return res;
}
 
int main(){
    int query, i, j, k = 0, x, a, b;
    fread_unlocked(str, 1, 10000000, stdin);
    for (i = 0; i < 25; i++) ar[0][i] = 0;
 
    while (str[k] < 48 || str[k] > 57) k++;
    for (; str[k] > 47 && str[k] < 58; k++) n = T(n);
 
    for (i = 1; i <= n; i++){
        x = 0;
        while (str[k] < 48 || str[k] > 57) k++;
        for (; str[k] > 47 && str[k] < 58; k++) x = T(x);
 
        for (j = 0; j < 25; j++){
            ar[i][j] = ar[i - 1][j];
            int p = primes[j];
            while ((x % p) == 0){
                ar[i][j]++;
                x /= p;
            }
        }
    }
 
    while (str[k] < 48 || str[k] > 57) k++;
    for (; str[k] > 47 && str[k] < 58; k++) q = T(q);
 
    for (query = 0; query < q; query++){
        a = 0, b = 0, MOD = 0;
 
        while (str[k] < 48 || str[k] > 57) k++;
        for (; str[k] > 47 && str[k] < 58; k++) a = T(a);
 
        while (str[k] < 48 || str[k] > 57) k++;
        for (; str[k] > 47 && str[k] < 58; k++) b = T(b);
 
        while (str[k] < 48 || str[k] > 57) k++;
        for (; str[k] > 47 && str[k] < 58; k++) MOD = T(MOD);
 
 
        long long int res = 1;
        if (MOD > 1){
            for (j = 0; j < 25; j++){
                x = ar[b][j] - ar[a - 1][j];
                if (x){
                    int y = bigmod(primes[j], x);
                    res = (res * y) % MOD;
                }
            }
        }
        else res = 0;
 
        j = 0;
        x = res;
        for (; ;){
            if (!x) break;
 
            str3[j++] = (x % 10) + 48;
            x *= 0.1;
        }
 
        if (!j) str3[j++] = 48;
        for (i = j - 1; i >= 0; i--) str2[ye++] = str3[i];
        str2[ye++] = 10;
    }
 
    fwrite_unlocked(str2, 1, ye, stdout);
    return 0;
}