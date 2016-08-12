#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
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
const int inf = 0x3f3f3f3f, N = 2e1 + 5, MOD = 1e9 + 7;

int T, cas = 0;
map<string, int> SI;
vector<string> name;

int g[N][N], vis[N];
int id, n, m;

void init() {
	id = 0;
	SI.clear(), name.clear();
	mem(g, 0), mem(vis, 0);
}

void dfs(int u) {
	vis[u] = 1;
	
	rep(i, n) if(g[u][i] && g[u][i] == g[i][u]) if(!vis[i])
	cout << ", " << name[i], dfs(i);
}

void solve() {
	init();

	rep(i, m) {
		string s1, s2;
		cin >> s1 >> s2;

		if(!SI.count(s1)) SI[s1] = id ++, name.pb(s1);
		if(!SI.count(s2)) SI[s2] = id ++, name.pb(s2);

		int u = SI[s1], v = SI[s2];
		g[u][v] = 1;
	}

	rep(k, n) rep(i, n) if(g[i][k]) rep(j, n) if(g[k][j]) g[i][j] = 1;

	if(cas ++) ET;
	printf("Calling circles for data set %d:\n", cas);
	rep(i, n) if(!vis[i]) cout << name[i], dfs(i), ET;
}

// #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
																
    while(~sii(n, m), n + m) solve();
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}