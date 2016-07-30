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
int in[N], head[N], ans[N];
struct edge {
	int to, next;
} a[3 * N];
int ne;
void addEdge(int u, int v) {
	a[ne].to = v;
	in[v] ++;
	a[ne].next = head[u];
	head[u] = ne ++;
}

bool Topo() {
	queue<int> que;
	int num = 0;
	for(int i = 1; i <= n; i ++) if(!in[i]) que.push(i);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		-- in[u];
		ans[num ++] = u;
		for(int i = head[u]; i != -1; i = a[i].next)
			if(-- in[i] == 0) que.push(i);
	}
	if(num >= k) return true;
	return false;
}

void init() {
	mem(head, -1);
	mem(in, 0);
}



#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m), n + m) {
    	init();
    	for(int i = 0; i < m; i ++) {
    		int u, v;
    		sii(u, v);
    		addEdge(u, v);
    	}
    	Topo();
    }
    
    return 0;
}