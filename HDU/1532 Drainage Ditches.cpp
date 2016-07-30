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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;

struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct EdmondsKarp {
	int n, m;
	vector<Edge> edges;
	vector<int> G[N];
	int a[N], p[N];

	void init() {
		rep(i, n) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int cap) {
		edges.pb(Edge(from, to, cap, 0));
		edges.pb(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].pb(m-2);
		G[to].pb(m-1);
	}

	int Maxflow(int s, int t) {
		int flow = 0;
		while(1) {
			mem(a, 0);
			queue<int> que;
			que.push(s);
			a[s] = inf;
			while(!que.empty()) {
				int x = que.front(); que.pop();
				int sz = G[x].size();
				rep(i, sz) {
					Edge& e = edges[G[x][i]];
					if(!a[e.to] && e.cap > e.flow) {
						p[e.to] = G[x][i];
						a[e.to] = min(a[x], e.cap - e.flow);
						que.push(e.to);
					}
				}
				if(a[t]) break;
			}
			if(!a[t]) break;

			for(int u = t; u != s; u = edges[p[u]].from) {
				edges[p[u]].flow += a[t];
				edges[p[u]^1].flow -= a[t];
			}

			flow += a[t];
		}
		return flow;
	}
};

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(m, n) != EOF) {
    	EdmondsKarp ans;
    	int u, v, d;
    	rep(i, m) {
    		siii(u, v, d);
    		ans.AddEdge(u, v, d);
    	}
    	printf("%d\n", ans.Maxflow(1, n));
    }
    
    return 0;
}