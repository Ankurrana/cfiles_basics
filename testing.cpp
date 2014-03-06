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


int main(){
	cin.sync_with_stdio(0);
	FastInput fin;
  	FastOutput fout;

  	int n = fin.readuint();
  	fout.writeuint(n);
    fout.putchar('\n');

	return 0;
}
 