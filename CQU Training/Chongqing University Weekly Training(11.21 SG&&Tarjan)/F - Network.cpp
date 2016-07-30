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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, q;
int dfn[N], low[N], fa[N], head[N];
bool bridge[N], vis[N];
struct edge {
	int v, next;
}e[4 * N];
int bridgeNum = 0, ne = 0, dfsNum = 0;
void addEdge(int u, int v) {
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne ++;
}

void init() {
	mem(dfn, 0), mem(low, 0), mem(vis, 0), mem(bridge, 0);
	mem(fa, -1), mem(head, -1);
	dfsNum = bridgeNum = ne = 0;
}

void Tarjan(int u, int father) {
	dfn[u] = low[u] = ++ dfsNum;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			vis[v] = 1;
			fa[v] = u;
			Tarjan(v, u);
			Min(low[u], low[v]);
			if(dfn[u] < low[v]) {
				bridgeNum ++;
				bridge[v] = 1;
			}
		} else if(v != father) Min(low[u], dfn[v]);
	}
}

void work(int u) {
	if(bridge[u]) bridgeNum --, bridge[u] = 0;
}

void lca(int u, int v) {
	if(dfn[u] > dfn[v]) swap(u, v);
	while(dfn[u] < dfn[v]) {
		work(v);
		v = fa[v];
	}
	while(v != u) {
		work(u);
		work(v);
		u = fa[u], v = fa[v];
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF, n + m) {
    	init();
    	int u, v;
    	rep(i, m) {
    		sii(u, v);
    		addEdge(u, v);
    		addEdge(v, u);
    	}
    	FOR(i, 1, n + 1) fa[i] = i;
    	Tarjan(1, -1);
		printf("Case %d:\n", ++ cas);
		si(q);
		rep(i, q) {
			sii(u, v);
			lca(u, v);
			printf("%d\n", bridgeNum);
		} puts("");
    }
    
    return 0;
}