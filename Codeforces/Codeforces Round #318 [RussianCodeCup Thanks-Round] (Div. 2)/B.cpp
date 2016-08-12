// Header.
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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 4e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int g[N][N], vis[N];
int a[N], b[N], in[N];
// Imp
VI son[N];

#define LOCAL
int main(){
#ifdef LOCAL
    IN // OUT
#endif
	

	int ans = inf;
    sii(n, m);
    mem(g, 0);
    mem(vis, 0);
    rep(i, m) {
    	sii(a[i], b[i]);
    	son[a[i]].pb(b[i]);
    	son[b[i]].pb(a[i]);
    	g[a[i]][b[i]] = g[b[i]][a[i]] = 1;
    }
    FOR(i, 1, n) {
    	int len = son[i].size();
    	rep(j, len) {
    		int p = son[i][j];
    		if(vis[p]) continue;
    		REP(k, i + 1, len) {
    			int q = son[i][k];
    			if(vis[q]) continue;
    			if(g[p][q]) {
    				int t = len + son[q].size() + son[p].size() - 6;
    				Min(ans, t);
    			}
    		}
    	}
    	vis[i] = 1;
    }
    if(ans == inf) ans = -1;
    put(ans);
    return 0;
}