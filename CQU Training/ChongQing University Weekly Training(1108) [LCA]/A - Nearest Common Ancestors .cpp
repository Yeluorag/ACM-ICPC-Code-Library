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
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;
const int M = 30;

int T, cas = 0;
int n, m;
struct edge {
	int v, next;
}e[2 * N];
int ne, root, head[N];
int fa[N][M], depth[N], vis[N];

void addEdge(int u, int v) {
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne ++;
}

void init() {
	mem(vis, 0);
	mem(depth, 0);
	mem(head, -1);
	mem(fa, -1);
	ne = 0;
}

void doubly() {
	for(int j = 1; (1 << j) <= n; j ++)
		FOR(i, 1, n)
			if(fa[i][j-1] != -1)
				fa[i][j] = fa[fa[i][j-1]][j-1];
}

void dfs(int u) {
	for(int i = head[u]; i != -1; i = e[i].next) {
		if(!depth[e[i].v]) {
			depth[e[i].v] = depth[u] + 1;
			fa[e[i].v][0] = u;
			dfs(e[i].v);
		}
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	int d = depth[u] - depth[v];
	rep(i, M) if((1 << i) & d) u = fa[u][i];
	if(u == v) return u;
	for(int i = M - 1; i >= 0; i --) {
		if(fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return u = fa[u][0];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	init();
    	int u, v;
    	rep(i, n - 1) {
    		sii(u, v);
    		addEdge(u, v);
    		fa[v][0] = u;
    		if(fa[u][0] == -1) root = u;
    	}
    	depth[root] = 1;
    	dfs(root);
    	doubly();
    	sii(u, v);
    	printf("%d\n", lca(u, v));
    }
    
    return 0;
}