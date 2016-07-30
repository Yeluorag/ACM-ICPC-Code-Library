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
const int inf = 0x3f3f3f3f, N = 2e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int ne, top, dfsNum;
int head[N], dfn[N], low[N], st[N], vis[N];
vector<int> node;
struct edge {
	int v, next;
}e[2 * N];
void addEdge(int u, int v) {
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne ++;
}

void init() {
	mem(dfn, 0), mem(low, 0);
	mem(vis, 0), mem(head, -1);
	ne = top = dfsNum = 0;
	node.clear();
}

void Tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ dfsNum;
	st[top ++] = u;
	vis[u] = 1;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			Tarjan(v, u);
			Min(low[u], low[v]);
		} else if(vis[v]) Min(low[u], dfn[v]);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF, n + m) {
    	init();
    	int u, v, root;
    	rep(i, m) {
    		sii(u, v);
    		addEdge(u, v);
    		root = u;
    		if(!vis[u]) node.pb(u);
    		if(!vis[v]) node.pb(v);
    		vis[u] = vis[v] = 1;
    	}
    	// root = 1;
    	mem(vis, 0);
    	Tarjan(root, 0);
    	int sz = node.size(), ans = 1;
    	rep(i, sz) {
    		if(low[node[i]] > 1 || low[node[i]] == 0) ans = 0;
    	}
    	printf("%s\n", ans ? "Yes" : "No");
    }
    
    return 0;
}