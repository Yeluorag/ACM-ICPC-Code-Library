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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
LL dp[20][50][2600], l, r;
int bit[20], hs[2600];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
LL dfs(int now, int lcm, int mod, bool flag) {
	LL& ret = dp[now][hs[lcm]][mod];
	if(now == 0) return mod % lcm == 0;
	if(flag && ret != -1) return ret;
	LL ans = 0;
	int x = flag ? 9 : bit[now];
	for(int i = 0; i <= x; i ++) {
		int _lcm = !i ? lcm : (lcm * i / gcd(lcm, i)),
			_mod = (mod * 10 + i) % 2520;
		ans += dfs(now - 1, _lcm, _mod, flag || i < x);
	}
	if(flag) ret = ans;
	return ans;
}

LL work(LL x) {
	int len = 0;
	while(x) {
		bit[++ len] = x % 10;
		x /= 10;
	}
	return dfs(len, 1, 0, 0);
}

void init() {
	int idx = 1;
	for(int i = 1; i <= 2520; i ++) {
		if(2520 % i == 0) hs[i] = idx ++;
	}
	mem(dp, -1);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

	init();
	si(T);
	while(T --) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", work(r) - work(l - 1));
	}
    
    
    return 0;
}