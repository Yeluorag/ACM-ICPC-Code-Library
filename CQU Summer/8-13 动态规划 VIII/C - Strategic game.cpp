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
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1500 + 5, MOD = 1e9 + 7;

int n, nd, num, vis[N], flag[N];
VI son[N];

bool dfs(int u) {
	int len = son[u].size();
	rep(i, len) {
		int v = son[u][i];
		if(vis[v]) continue;
		vis[v] = 1;
		if(flag[v] == -1 || dfs(flag[v])) {
			flag[v] = u;
			return true;
		}
	}
	return false;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(~si(n)) {
    	mem(flag, -1);
    	rep(i, N) son[i].clear();
    	rep(i, n) {
    		int t;
    		scanf("%d:(%d)", &nd, &num);
    		rep(i, num) {
    			si(t);
    			son[nd].pb(t);
    			son[t].pb(nd);
    		}
    	}
    	int ans = 0;
    	rep(i, n) { 
    		mem(vis, 0);
    		ans += dfs(i);
    	}
    	put(ans / 2);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}