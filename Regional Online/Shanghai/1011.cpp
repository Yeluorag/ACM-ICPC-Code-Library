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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int C, k1, k2, b1;
LL l, b, r;
bool flag;

// Imp
LL quick_mod(LL a, LL b, LL m) {
	LL ret = 1;
	a %= m;
	while(b > 0) {
		if(b & 1) ret = ret * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(~scanf("%d%d%d%d", &C, &k1, &b1, &k2)) {
    	flag = false;
    	printf("Case #%d:\n", ++ cas);
    	for(int i = 1; i < C; i ++) {
    		l = quick_mod(i, k1, C);
    		b = C - quick_mod(i, k1 + b1, C);
    		r = quick_mod(b, k2, C);
    		if(l == r) flag = true, printf("%d %lld\n",i, b);
    	}
    	if(!flag) puts("-1");
    }

    
    return 0;
}