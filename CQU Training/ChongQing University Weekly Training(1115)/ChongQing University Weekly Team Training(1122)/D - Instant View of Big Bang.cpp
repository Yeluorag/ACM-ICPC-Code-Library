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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct edge {
	int v, w;
	int next;
	edge(){}
	edge(int v, int w) : v(v), w(w) {}
 } e[2 * N];
 int head[N], inq[N], ok[N], d[N], cnt[N], vis[N];
 int ne;
 void init() {
 	mem(head, - 1);
 	mem(ok, 0);
 	mem(inq, 0);
 	mem(cnt, 0);
 	mem(vis, 0);
 	ne = 0;
 }

 void addEdge(int u, int v, int w) {
 	e[ne].v = v;
 	e[ne].w = w;
 	e[ne].next = head[u];
 	head[u] = ne ++;
 }

void bfs(int rt) {
	queue<int> que;
	que.push(rt);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		ok[u] = true;
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if(ok[v]) continue;
			que.push(v);
		}
	}
}

// bool dfs(int u) {
// 	vis[u] = 1;
// 	for(int i = head[u]; i != -1; i = e[i].next) {
// 		int v = e[i].v, w = e[i].w;
// 		if(d[v] > d[u] + w) {
// 			d[v] = d[u] + w;
// 			if(!vis[v]) {
// 				if(dfs(v)) {
// 					bfs(v);
// 					return true;
// 				}
// 			} else return true;
// 		}
// 	}

// 	return false;
// }

void spfa() {
	queue<int> que;
	for(int i = 0; i < n; i ++) {
		d[i] = 0;
		que.push(i);
	}
	while(!que.empty()) {
		int u = que.front(); que.pop();
		if(ok[u]) continue;
		inq[u] = false;
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if(d[v] > d[u] + e[i].w) {
				d[v] = d[u] + e[i].w;
				if(!inq[v]) {
					inq[v] = true;
					que.push(v);
					if(++ cnt[v] > n) bfs(v);
				}
			}
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	init();
    	sii(n, m);
    	int u, v, w;
    	for(int i = 0; i < m; i ++) {
    		siii(u, v, w);
    		addEdge(v, u, w);
    	}
    	// for(int i = 0; i < n; i ++) {
    	// 	if(!vis[i]) dfs(i); 
    	// }
    	spfa();
    	printf("Case %d:", ++ cas);
    	int ans = 1;
    	for(int i = 0; i < n; i ++) {
    		if(ok[i]) {
    			ans = 0;
    			printf(" %d", i);
    		}
    	}
    	if(ans) puts(" impossible");
    	else puts("");
    }
    
    return 0;
}