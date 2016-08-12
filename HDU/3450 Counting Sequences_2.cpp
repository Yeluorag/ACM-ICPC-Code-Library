#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
#define lowbit(x) x & -x
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 9901;

int T, cas = 0;
int n, d;
int a[N];

int bit[N];
int sum(int i) {
	int ret = 0;
	while(i > 0) {
		ret = (ret + bit[i]) % MOD;
		i -= lowbit(i);
	}
	return ret;
}

void update(int i, int x) {
	while(i < N) {
		bit[i] = (bit[i] + x) % MOD;
		i += lowbit(i);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, d) != EOF) {
    	vector<int> b;
    	b.pb(-inf);
    	FOR(i, 1, n) { 
    		si(a[i]);
    		b.pb(a[i]);
    	}
    	sort(ALL(b));
    	b.erase(unique(ALL(b)), b.end());
    	mem(bit, 0);
    	FOR(i, 1, n) {
    		int now = lower_bound(ALL(b), a[i]) - b.begin(),
    		l = lower_bound(ALL(b), a[i] - d) - b.begin(),
    		r = upper_bound(ALL(b), a[i] + d) - b.begin() - 1;
    		int tmp = (sum(r) - sum(l - 1) + 1 + MOD) % MOD;
    		update(now, tmp);
    	}

    	printf("%d\n", ((sum(b.size() - 1) - n) % MOD + MOD) % MOD);
    }
    
    return 0;
}