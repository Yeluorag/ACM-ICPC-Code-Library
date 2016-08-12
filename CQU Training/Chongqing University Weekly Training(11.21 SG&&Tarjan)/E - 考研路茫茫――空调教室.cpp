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
#define Min(a, b) a = min(a, b)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ne, ans, all, top, bch, dfsNum;
int a[N], head[N], dfn[N], low[N], tree[N], sum[N], col[N],st[N];
vector<pair<int, int> > bridge;
bool vis[N];
struct edge {
	int v, next;
}e[10 * N];

void addEdge(int u, int v) {
	e[ne].v = v,
	e[ne].next = head[u],
	head[u] = ne ++;
}

void init() {
	mem(tree, -1), mem(head, -1), mem(col, -1);
	mem(vis, 0), mem(sum, 0);
	bridge.clear();
	bch = top = all = ne = dfsNum = 0;
}

void Tarjan(int u, int fa) {
	dfn[u] = low[u] = dfsNum ++;
	vis[u] = 1;
	st[top ++] = u;
	int flag = 0;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(v == fa && !flag) { flag = 1; continue; }
		if(!vis[v]) {
			Tarjan(v, u);
			Min(low[u], low[v]);
		} else if(col[v] == -1) Min(low[u], dfn[v]);
		if(dfn[u] < low[v]) bridge.pb(make_pair(u, v));
	}
	if(low[u] == dfn[u]) {
		while(st[top - 1] != u) col[st[--top]] = bch, sum[bch] += a[st[top]];
		top --;
		sum[bch] += a[st[top]];
		col[u] = bch ++;;
	}
}

void BuildTree() {
	int sz = bridge.size();
	rep(i, sz) {
		int u = bridge[i].first, v = bridge[i].second;
		e[ne].v = col[v], e[ne].next =  tree[col[u]];
		tree[col[u]] = ne ++;
		e[ne].v = col[u], e[ne].next = tree[col[v]];
		tree[col[v]] = ne ++;
	}
}

int dfs(int u) {
	int tmp = sum[u];
	vis[u] = 1;
	for(int i = tree[u]; i != -1; i = e[i].next) 
		if(!vis[e[i].v]) tmp += dfs(e[i].v);
	Min(ans, abs(all - 2 * tmp));
	return tmp;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	init();
    	rep(i, n) si(a[i]), all += a[i];
    	int u, v;
    	rep(i, m) {
    		sii(u, v);
    		addEdge(u, v);
    		addEdge(v, u);
    	}

    	Tarjan(0, 0);
    	if(bch != 1) {
    		BuildTree();
    		mem(vis, 0);
    		ans = inf;
    		dfs(0);
    		printf("%d\n", ans);
    	} else puts("impossible");
    }
    
    return 0;
}