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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ne;
struct edge {
	int v, next;
}e[4 * N];
int head[N], vis[N], ans[N], fa[N], in[N];
vector<int> query[N];
void addEdge(int u, int v) {
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne ++;
}

int find(int x) {
	if(x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

void Tarjan(int u) {
	fa[u] = u;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(!vis[v]) {
			Tarjan(v);
			fa[v] = u;
		}
	}
	vis[u] = 1;
	int len = query[u].size();
	rep(i, len) {
		int v = query[u][i];
		int k = find(v);
		if(vis[v]) ans[k] ++;
 	}
}

void init() {
	ne = 0;
	mem(in, 0);
	mem(ans, 0);
	mem(vis, 0);
	mem(head, -1);
	rep(i, N) query[i].clear();
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	init();
    	int u, v;
    	rep(i, n) {
    		scanf("%d:(%d) ", &u, &m);
    		rep(j, m) si(v), in[v] ++, addEdge(u, v);
    	} si(m);
    	rep(i, m) {
    		while(getchar() != '(');
    		scanf("%d %d", &u, &v);
    		query[u].pb(v);
    		query[v].pb(u);
    		while(getchar() != ')');
    	}
    	FOR(i, 1, n) if(!in[i]) {
    		Tarjan(i);
    		break;
    	}
    	FOR(i, 1, n) if(ans[i]) printf("%d:%d\n", i, ans[i]);
    }
    
    return 0;
}