// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int e, s, t, st, des, row[N], col[N];
int head[N], pnt[N * N], nxt[N * N], flow[N * N], vis[N];
int ans[N][N];
queue<int> que;
// Imp
void AddEdge(int u, int v, int f) {
	pnt[e] = v; nxt[e] = head[u]; flow[e] = f; head[u] = e ++;
	pnt[e] = u; nxt[e] = head[v]; flow[e] = 0; head[v] = e ++;
}

bool bfs() {
	mem(vis, 0);
	vis[st] = 1;
	que.push(st);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int i = head[u]; i != -1; i = nxt[i]) {
			if(flow[i] && !vis[pnt[i]]) {
				vis[pnt[i]] = vis[u] + 1;
				que.push(pnt[i]);
			}
		}
	}
	return vis[des];
}

int dfs(int u, int maxf) {
	if(u == des || !maxf) return maxf;
	for(int i = head[u], t; i != -1; i = nxt[i]) {
		if(vis[pnt[i]] == vis[u] + 1 && (t = dfs(pnt[i], min(flow[i], maxf)))) {
			flow[i] -= t;
			flow[i^1] += t;
			return t;
		}
	}
	return vis[u] = 0;
}

void MaxFlow() {
	int ans = 0;
	while(bfs()) {
		while(true) {
			int res = dfs(st, inf);
			if(!res) break;
			ans += res;
		}
	}
}

void init() {
 	e = s = 0;
 	t = n + m + 1;
 	st = n + m + 2;
 	des = n + m + 3;
 	mem(head, -1);
 	FOR(i, 1, n) AddEdge(s, i, row[i] - row[i-1]);
 	FOR(i, 1, n) FOR(j, 1, m) {
 		AddEdge(i, des, 1);
 		AddEdge(i, n + j, 19);
 		AddEdge(st, n + j, 1);
 	}
 	FOR(i, 1, m) AddEdge(n + i, t, col[i] - col[i-1]);
 	AddEdge(t, s, inf);
}

void read() {
    sii(n, m);
    FOR(i, 1, n) si(row[i]);
    FOR(i, 1, m) si(col[i]);
}

// Main Pro
void solve() {
    read(), init();
    MaxFlow();
    st = 0, des = n + m + 1;
    MaxFlow();
    for(int i = 0; i < e; i += 2) 
    	if(pnt[i^1] > s && pnt[i ^ 1] <= n && pnt[i] > n && pnt[i] < t)
    		ans[pnt[i^1]][pnt[i] - n] = flow[i^1];
    if(cas ++) ET;
    printf("Matrix %d\n", cas);
    FOR(i, 1, n) FOR(j, 1, m)
    printf("%d%c", ans[i][j] + 1, j == m ? '\n' : ' ');
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif


    si(T); while(T --) solve();
    // while(~si(n), n) solve();
    // while(~sii(n, m), n + m) solve();
    
  
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}