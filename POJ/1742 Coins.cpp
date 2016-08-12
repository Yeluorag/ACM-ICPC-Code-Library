// Header.
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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int u, int v, int cap): u(u), v(v), cap(cap) {}
}es[N * N];
int ne, st, ed;
vector<int> tab[N];
int dis[N], cur[N];
void addEdge(int u, int v, int cap) {
	tab[u].pb(ne);
	es[ne++] = edge(u, v, cap);
	tab[v].pb(ne);
	es[ne++] = edge(v, u, 0);
}
// Imp
// Dinic
int bfs() {
	queue<int> que;
	que.push(st);
	mem(dis, 0x3f);
	dis[s] = 0;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int i = 0; i < tab[h].size(); i ++) {
			edge& e = es[tab[u][i]];
			if(e.cap > 0 && dis[e.v] == inf) {
				dis[e.v] = dis[u] + 1;
				que.push(e.v);
			}
		}
	}
	return dis[T] < inf;
}

int dfs(int x, int maxflow) {
	if(x == ed) return maxflow;
	for(int i = cur[x]; i < tab[x].size(); i ++) {
		cur[x] = x;
		edge& e = es[tab[x][i]];
		if(dis[e.v] == dis[x] + 1 && e.cap > 0) {
			int flow = dfs(e.v, min(maxflow, e.cap));
			if(flow) {
				e.cap -= flow;
				es[tab[x][i]^1].cap += flow;
				return flow;
			}
		}
	}
	return 0;
}

int Dinic() {
	int ret = 0;
	while(bfs()) {
		int flow;
		mem(cur, 0);
		while(flow = dfs(st, inf)) ret += flow;
	}
	return ret;
}


#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    
    
    return 0;
}