// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
struct edge{
	int v, next;
}e[5 * N];
int ne, head[N];
void InitEdge() {
	ne = 0;
	mem(head, -1);
}
void addEdge(int u, int v) {
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne ++;
	e[ne].v = u;
	e[ne].next = head[v];
	head[v] = ne ++;
}
int low[N], dfn[N], cut[N], sub[N];
int rootsub, depth;
// Imp
void Tarjan(int u, int fa) {
	low[u] = dfn[u] = ++ depth;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(v == fa) continue;
		if(!dfn[v]) {
			Tarjan(v, u);
			Min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				if(u != 1) sub[u] ++;
				else rootsub ++;
			}
		} else Min(low[u], dfn[v]);
	}
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
	int u, v;
    while(si(u), u) {
    	InitEdge();
    	mem(dfn, 0);
    	si(v), addEdge(u, v);
    	int node = max(u, v);
    	while(si(u), u) {
    		si(v), addEdge(u, v);
    		node = max(u, v);
    	}
    	rootsub = ne = 0;
    	mem(sub, 0);
    	Tarjan(1, 1);
    	if(cas ++) puts("");
    	printf("Network #%d\n", cas);
    	if(rootsub > 1) sub[1] = rootsub - 1;
    	bool ok = false;
    	FOR(i, 1, node) {
    		if(sub[i]) {
    			ok = true;
    			printf("  SPF node %d leaves %d subnets\n", i, sub[i] + 1);
    		}	
    	}
    	if(!ok) puts("  No SPF nodes");
    }
    
    return 0;
}