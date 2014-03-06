#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
typedef __int64 LL;

int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int nprime = 25;

int tree[25][100005];

//Calculates bigmod
inline LL bigmod(LL a, LL b, LL m)
{
	if(b == 0) return 1 % m;

	LL x = a, ans = 1;

	while(b)
	{
		if(b&1) ans = (ans * x)%m;
		b >>= 1;
		x = (x*x)%m;
	}
	
	return ans;
}

char line[400000];
int now = 0;

//fast input integer from console
inline int getn(){

	int n;

	while(1)
	{
		if(line[now]!=0)
		{
			if(line[now]<'0' || line[now]>'9') { now++; continue; }
			n = 0;
			while(line[now]>='0' && line[now]<='9') {n = n*10 + line[now] - '0'; now++;}
			return n;

		}
		else
		{
			gets(line);
			now = 0;
		}
	}

	return n;
}

vector<PII> V[102];

int main()
{
	int n, a, j, i, cnt;
	int l, r, m, t;
	LL ans;

	//Generating prime factors
	for(i = 2; i <= 100; i++)
	{
		a = i;
		for(j = 0; j < nprime; j++)
		{
			cnt = 0;
			while(a % prime[j] == 0)
				cnt++, a /= prime[j];

			if(cnt)
				V[i].push_back( PII(j, cnt) );

			if(a == 1)
				break;
		}

	}

	n = getn();
	IN(n, 1, 100000);

	//tree is an array which stores cumulative sum of prime powers for each prime\
	//using the pregenerated prime factor table
	for(i = 1; i <= n; i++)
	{
		a = getn();
		IN(a, 1, 100);

		for(j = V[a].size() - 1; j >= 0; j--)
			tree[V[a][j].first][i] += V[a][j].second;

		for(j = 0; j < nprime; j++)
			tree[j][i] += tree[j][i - 1];
	}

	t = getn();
	while( t-- )
	{
		l = getn();
		r = getn();
		m = getn();

		IN(l, 1, r);
		IN(r, l, n);
		IN(m, 1, 1000000000);

		ans = 1 % m;
		for(j = 0; j < nprime; j++)
		{
			//for each prime, find the number of this prime factor in the given segment.
			cnt = tree[j][r] - tree[j][l-1];
			if(cnt) ans = (ans * bigmod(prime[j], cnt, m))%m;
			if(ans == 0) break;
		}

		printf("%I64d\n", ans);
	}


	return 0;
}