// Header. Tarjan
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
#define x first
#define y second
const int inf = 0x3f3f3f3f, N = 4e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, par[N], vis[N], dis[N], ans[N];
vector<pair<int, int> > son[N];
vector<pair<int, int> > query[N];
// Imp
int find(int x) {
	if(x != par[x]) return par[x] = find(par[x]);
	return x;
}

void Tarjan(int u) {
	vis[u] = 1;
	par[u] = u;
	int len = son[u].size();
	rep(i, len) {
		int v = son[u][i].x;
		if(!vis[v]) {
			dis[v] = dis[u] + son[u][i].y;
			Tarjan(v);
			par[v] = u;
		}
	}
	len = query[u].size();
	rep(i, len) {
		int v = query[u][i].x, idx = query[u][i].y;
		if(vis[v]) ans[idx] = dis[u] + dis[v] - 2 * dis[find(v)];
	}
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	int u, v, d;
    	rep(i, N) son[i].clear(), query[i].clear();
    	mem(vis, 0);
    	rep(i, n - 1) {
    		siii(u, v, d);
    		son[u].pb(make_pair(v, d));
    		son[v].pb(make_pair(u, d));
    	}
    	rep(i, m) {
    		sii(u, v);
    		query[u].pb(make_pair(v, i));
    		query[v].pb(make_pair(u, i));
    	}
    	mem(vis, 0);
    	dis[1] = 0;
    	Tarjan(1);
    	rep(i, m) put(ans[i]);
    }
    
    return 0;
}