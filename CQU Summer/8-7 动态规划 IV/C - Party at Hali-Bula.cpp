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
const int inf = 1 << 30, N = 2e2 + 5, MOD = 1e9 + 7;

VI son[N];
map<string, int> mp;
int n, dp[N][2], f[N][2];

void dfs(int u) {
	dp[u][0] = 0; dp[u][1] = 1;
	f[u][0] = f[u][1] = 1;
	int len = son[u].size();
	rep(i, len) {
		int v = son[u][i];
		dfs(v);
		if(dp[v][0] == dp[v][1]) {
			dp[u][0] += dp[v][0];
			f[u][0] = 0;
		} else {
			int idx = dp[v][0] > dp[v][1] ? 0 : 1;
			dp[u][0] += dp[v][idx];
			if(!f[v][idx]) f[u][0] = 0;
		}
		dp[u][1] += dp[v][0];
		if(!f[v][0]) f[u][1] = 0;
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n), n) {
    	mem(dp, 0);
    	mem(f, -1);
    	mp.clear();
    	rep(i, N) son[i].clear();
    	string s1, s2;
    	int idx = 1;
    	cin >> s1; mp[s1] = idx ++;
    	rep(i, n - 1) {
    		cin >> s1 >> s2; 
    		if(!mp[s1]) mp[s1] = idx ++;
    		if(!mp[s2]) mp[s2] = idx ++;
    		int a = mp[s1], b = mp[s2];
    		son[b].pb(a);
    	} dfs(1);
    	if(dp[1][0] == dp[1][1]) f[1][0] = f[1][1] = 0;
    	idx = dp[1][0] > dp[1][1] ? 0 : 1;
    	printf("%d %s\n",  dp[1][idx], f[1][idx] ? "Yes" : "No");
    }
    
    return 0;
}