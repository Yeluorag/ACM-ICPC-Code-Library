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
#define Min(a, b) a = min(a, b)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 2e4 + 5, M = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int ne, dfsNum, top, tot;
struct edge {
	int v, next;
}e[M];
int head[M], dfn[N], low[N], vis[N], st[N], g[N], in[N], out[N];
void addEdge(int u, int v) {
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne ++;
}
void init() {
	mem(dfn, 0), mem(low, 0), mem(vis, 0);
	mem(in, 0), mem(out, 0), mem(g, 0), mem(head, -1);
	dfsNum = ne  = top = tot = 0;
}

void Tarjan(int u) {
	dfn[u] = low[u] = ++ dfsNum;
	st[top ++] = u;
	vis[u] = 1;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			Tarjan(v);
			Min(low[u], low[v]);
		} else if(vis[v]) Min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		tot ++;
		while(1) {
			int k = st[-- top];
			g[k] = tot;
			vis[k] = 0;
			if(k == u) break;
		}
	}
}

void work() {
	for(int u = 1; u <= n; u ++) {
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if(g[u] == g[v]) continue;
			out[g[u]] ++;
			in[g[v]] ++;
		}
	}
}

void gao() {
	work();
	int ans1 = 0, ans2 = 0, ans;
	for(int i = 1; i <= tot; i ++) {
		if(in[i] == 0) ans1 ++;
		if(out[i] == 0) ans2 ++;
	}
	ans = max(ans1, ans2);
	if(tot == 1) ans = 0;
	printf("%d\n", ans);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	init();
    	sii(n, m);
    	int u, v;
    	for(int i = 0; i < m; i ++) {
    		sii(u, v);
    		addEdge(u, v);
    	}
    	for(int u = 1; u <= n; u ++) if(!dfn[u]) Tarjan(u);
    	gao();
    }
    
    return 0;
}