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
const int inf = 0x3f3f3f3f, N = 1 << 20, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, a[45];
LL dp[45][N];

LL dfs(int i, int w) {
	LL& ret = dp[i][w];
	if(ret >= 0) return ret;
	if(i == n) return w >= m;
	ret = 0;
	ret += dfs(i + 1, w ^ a[i]) + dfs(i + 1, w);
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	rep(i, n) si(a[i]);
    	mem(dp, -1);
    	printf("Case #%d: %lld\n", ++ cas, dfs(0, 0));
    }
    
    return 0;
}