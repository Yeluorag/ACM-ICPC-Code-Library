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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ne;
struct edge {
	int v, w, next;
} e[4 * N];
int head[4 * N], dist[N], ed, Maxlen;
void addEdge(int u, int v, int w) {
	e[ne].v = v,
	e[ne].w = w,
	e[ne].next = head[u],
	head[u] = ne ++;
}

void dfs(int u, int fa, int len) {
	if(len > Maxlen) Maxlen = len, ed = u;
	for(int i = head[u]; ~i; i = e[i].next) {
		int v = e[i].v, w = e[i].w;
		if(v == fa) continue;
			dfs(v, u, len + w);
		dist[v] = max(dist[v], len + w);
	}
}
void init() {
	mem(dist, 0);
	mem(head, -1);
	Maxlen = 0;
	ne = 0;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	init();
    	int v, w;
    	for(int u = 2; u <= n; u ++) {
    		sii(v, w);
    		addEdge(u, v, w);
    		addEdge(v, u, w);
    	}
    	dfs(1, -1, 0);
    	dfs(ed, -1, 0);
    	dfs(ed, -1, 0);
    	for(int i = 1; i <= n; i ++) printf("%d\n", dist[i]);
    }
    
    return 0;
}