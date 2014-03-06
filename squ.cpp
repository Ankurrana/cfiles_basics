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
#define get getchar_unlocked
 
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



inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n << 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
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
	FastInput fin;
  	FastOutput fout;


  	int t = fin.readuint();
  	int x = 0,y = 0;
  	int f1 = 0,f2 = 0,f3 = 0,v = 0;

  	while(t--){

  		v = fin.readuint();
  		
  		while(v--){
	  		x = fin.scan2();
	  		y = fin.scan2();

	  		if(x == y)
	  			f1 = 1;
	  		else if(x < y)
	  			f2 = 1;
	  		else
	  			f3 = 1;
  		}

  		if(f1 || (f2 && f3))
  			printf("YES\n");
  		else
  			printf("NO\n");

  			f1 = 0;
  			f2 = 0; 
  			f3 = 0;	

  	}




	return 0;
}
 