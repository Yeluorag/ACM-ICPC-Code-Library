#define LOCAL
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
const int inf = 1 << 30, N = 1e4 + 5, MOD = 1e9 + 7;

int n, a, b ,dp[N][3], f[N];
VI son[N];
void dfs(int u) {
	int len = son[u].size();
	f[u] = 1;
	dp[u][0] = 1;
	dp[u][1] = 0;
	dp[u][2] = inf;
	VI tmp;
	rep(i, len) {
		int v = son[u][i];
		if(f[v]) continue;
		dfs(v);
		tmp.pb(v);
		dp[u][0] += min(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][2];
	}
	rep(i, tmp.size()) {
		int v = tmp[i];
		dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n) != EOF) {
    	if(n == -1) break;
    	if(!n) si(n);
    	mem(f, 0);
    	rep(i, N) son[i].clear();
    	rep(i, n - 1) { sii(a, b); son[a].pb(b); son[b].pb(a); }
    	dfs(1);
    	int ans = min(dp[1][0], dp[1][2]);
    	printf("%d\n", ans);
    }
    
    return 0;
}