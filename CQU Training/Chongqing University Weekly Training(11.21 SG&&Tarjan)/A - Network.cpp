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
#define Min(a, b) a = min(a, b)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e2 + 5, M = 1e4, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct edge{
	int v, next;
}e[2 * M];
int ne, dfsNum, ans, child, root;
int head[M], dfn[N], low[N], vis[N], col[N];

void addEdge(int u, int v) {
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne ++;
}

void init() {
	mem(dfn, 0), mem(low, 0), mem(col, 0);
	mem(vis, 0), mem(head, -1);
	ne = dfsNum = ans = child = 0;
}

void Tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ dfsNum;
	vis[u] = 1;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(v == fa) continue;
		if(!vis[v] && u == root) child ++;
		if(!dfn[v]) {
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(u == root) {
				if(child > 1 && !col[u]) col[u] = 1, ans++;
			} else if(dfn[u] <= low[v] && !col[u]) {
				col[u] = 1;
				ans ++;
			}
		} else if(vis[v]) low[u] = min(low[u], dfn[v]);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n), n) {
    	int u, v;
    	init();
    	char in[1005];
    	root = 1;
    	getchar();
    	while(gets(in)) {
    		stringstream ss(in);
    		ss >> u;
    		if(!u) break;
    		while(ss >> v) {
    			addEdge(u, v);
    			addEdge(v, u);
    		} 
    		root = u;
    	}
    	Tarjan(root, 0);
    	printf("%d\n", ans);
    }
    
    return 0;
}