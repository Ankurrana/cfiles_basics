#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
using namespace std;
#include <climits>
 
typedef unsigned long long uint64;
#define repeat(n) for (int repc = (n); repc > 0; --repc)
#define ZERO(v) memset((v), 0, sizeof (v))
#define ALL(x) (x).begin(), (x).end()
 
          class FastInput {
          public:
            FastInput() : ptr_(buf_), end_(buf_) { }
           
            unsigned char readchar() {
              if (ptr_ == end_) {
                ptr_ = buf_;
                end_ = buf_ + read(0, buf_, MAXBUF);
              }
              return *ptr_++;
            }
           
            unsigned readuint() {
              unsigned char ch;
              while (isspace(ch = readchar())) ;
           
              unsigned result = ch - '0';
              while (isdigit(ch = readchar())) {
                result = 10 * result + ch - '0';
              }
              return result;
            }
           
          private:
            static const int MAXBUF = 8192;
            char buf_[MAXBUF];
            char *ptr_, *end_;
          };
 
                          class FastOutput {
                          public:
                            FastOutput() : ptr_(buf_), end_(buf_ + BUFSIZE) { }
                           
                            ~FastOutput() {
                              flush();
                            }
                           
                            void flush() {
                              int rv = write(1, buf_, ptr_ - buf_);
                              (void)rv;
                              ptr_ = buf_;
                            }
                           
                            void putchar(unsigned char ch) {
                              if (ptr_ == end_) {
                                flush();
                              }
                              *ptr_++ = ch;
                            }
                           
                            void writeuint(unsigned x) {
                              char buf[50], *p = buf;
                              do { *p++ = '0'+x%10; x/=10; } while (x > 0) ;
                              do putchar(*--p); while (p != buf);
                            }
                           
                          private:
                            static const int BUFSIZE = 8192;
                            char buf_[BUFSIZE];
                            char *ptr_, *end_;
                          };
 
inline unsigned maybe_mod(uint64 x, unsigned mod) {
  return x < mod ? x : x % mod;
}
 
inline uint64 mult(unsigned a, unsigned b) {
  return uint64(a) * b;
}
 
unsigned modpow(unsigned a, unsigned b, unsigned c) {
  unsigned result = 1;            // assumes c > 1
  for (;;) {
    if (b % 2 == 1) {
      result = maybe_mod(mult(result, a), c);
    }
    b /= 2;
    if (b == 0) {
      break;
    }
    a = maybe_mod(mult(a, a), c);
  }
  return result;
}
 
int main() {
  cin.sync_with_stdio(0);
 
  vector<int> primes;
  for (int i=2; i<=100; ++i) {
    bool ok = true;
    for (int j=2; j<i; ++j) {
      if (i % j == 0) {
        ok = false;
      }
    }
    if (ok) {
      primes.push_back(i);
    }
  }
  int nprimes = primes.size();
 
  static int cnt[100001][25];
  ZERO(cnt[0]);
 
  FastInput fin;
  FastOutput fout;
  int n = fin.readuint();
  for (int i=1; i<=n; ++i) {
    memcpy(cnt[i], cnt[i-1], sizeof cnt[i]);
    int x = fin.readuint();
    for (int j=0; j<nprimes; ++j) {
      while (x % primes[j] == 0) {
        x /= primes[j];
        ++cnt[i][j];
      }
    }
  }
 
  int q = fin.readuint();
  repeat (q) {
    int l = fin.readuint(), r = fin.readuint(), mod = fin.readuint();
    unsigned result = mod > 1 ? 1 : 0;
 
    static vector<pair<int, int> > entries; entries.clear();
    for (int a=0; a<nprimes; ++a) {
      int n = cnt[r][a] - cnt[l-1][a];
      if (n > 0) {
        entries.push_back(make_pair(n, primes[a]));
      }
    }
 
    sort(ALL(entries), greater<pair<int, int> >());
    entries.push_back(make_pair(0, 1));
 
    unsigned a = 1;
    for (int i=0; i<(int)entries.size()-1; ++i) {
      a = maybe_mod(mult(a, entries[i].second), mod);
      unsigned now = entries[i].first - entries[i+1].first;
      if (now > 0) {
        result = maybe_mod(mult(result, modpow(a, now, mod)), mod);
      }
    }
 
    fout.writeuint(result);
    fout.putchar('\n');
  }
 
  return 0;
}