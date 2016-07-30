#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 1e5 + 5, MOD = 1e9 + 7;

int n, t, T;
VI son[N];

int dfs(int u) {
	if(son[u].empty()) return 1;
	int len = son[u].size();
	VI dp;
	rep(i, len) dp.pb(dfs(son[u][i]));
	sort(ALL(dp));
	int k = (len * T - 1) / 100 + 1, ret = 0;
	rep(i, k) ret += dp[i];
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(sii(n, T), n && T) {
    	rep(i, N) son[i].clear();
    	FOR(i, 1, n) { si(t); son[t].pb(i); }
    	int ans = dfs(0);
    	printf("%d\n", ans);
    }
    
    return 0;
}