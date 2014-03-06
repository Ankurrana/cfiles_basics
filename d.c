#include"cstdio"
#include"algorithm"
#include"cstring"
#include"vector"
using namespace std;
int ans[100001];
struct query {
    int l, r, k, idx;
    query(int i) {
        idx = i;
        scanf("%d%d%d", &l, &r, &k);
        l--, r--;
    }
};
vector<int> factors[100001];
int main() {
    for(int i=1; i<100001; i++)
        for(int j=i; j<100001; j+=i)
            factors[j].push_back(i);
    int N, Q;
    scanf("%d%d", &N, &Q);
    int a[N];
    for(int i=0; i<N; i++)
        scanf("%d", &a[i]);
    vector<query> qrs;
    for(int i=0; i<Q; i++)
        qrs.push_back(query(i));
    function<bool(const query&, const query&)> sort1 = [](const query& a, const query& b) { return a.l<b.l; },
                                  sort2 = [](const query& a, const query& b) { return a.r<b.r; };
    int idx = 0;
    for(auto fn: {sort1, sort2}) {
        sort(qrs.begin(), qrs.end(), fn);
        int count[100001];
        memset(count, 0, 100001*sizeof(int));
        auto qr = qrs.begin();
        for(int i=0; ; i++) {
            while(qr!=qrs.end() and ((idx==0 and qr->l<=i) or (idx and qr->r<i)))
                ans[qr->idx] += idx?count[qr->k]:-count[qr->k], qr++;
            if(qr==qrs.end())break;
            for(auto j: factors[a[i]])
                count[j]++;
        }
        idx++;
    }
    for(int i=0; i<N; i++)
        printf("%d\n", ans[i]);
}