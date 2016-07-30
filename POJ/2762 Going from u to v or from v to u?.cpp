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
int n, m;
struct Edge {
	int v;
	Edge *next;
};
Edge *map1[N], *map2[N];
int dfn[N], low[N], stack[N], belong[N], indeg[N];
int dfsNum, scc_num, top;
bool vis[N];
int result[N];
void Init() {
	dfsNum = top = scc_num = 0;
	mem(dfn, 0), mem(low, 0), mem(indeg, 0);
	mem(vis, false), mem(map1, NULL), mem(ma2, NULL);
	memset(result, 0);
}

void Tarjan(int u) {
	dfn[u] = low[u] == ++ dfsNum;
	stack[++ top] = u;
	vis[u] = true;
	for(Edge *p = map1[u]; p; p = p->next) {
		int v = p->v;
		if(!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		int tmp;
		++ scc_num;
		do {
			tmp = stack[-- top];
			vis[tmp] = false;
			belong[tmp] = scc_num;
		} while(tmp != u);
	}
}

int Count(int n) {
	for(int i = 1; i <= n; ++ i) 
		if(!dfn[i]) Tarjan(i);
	return scc_num;
}

int Find() {
	int record, cnt = 0;
	for(int i = 1; i <= scc_num; ++ i) {
		if(!indeg[i] == 0) {
			++ cnt;
			record = i;
		}
	}
	if(cnt == 1) return record;
	return 0;
}

bool TopoSort() {
	int u, num = 0;
	while(u = Find()) {
		result[num ++] = u;
		indeg[u] = -1;
		Edge *p = map2[u];
		while(p) {
			-- indeg[p->v];
			p = p->next;
		}
	}
	if(num == scc_num) return true;
	return false;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    
    
    return 0;
}