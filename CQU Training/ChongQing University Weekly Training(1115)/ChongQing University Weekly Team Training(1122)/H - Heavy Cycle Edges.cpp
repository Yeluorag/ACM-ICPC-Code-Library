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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, M = 3e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int fa[N];
struct edge {
	int u, v, w;
	edge() {}
	edge(int u, int v, int w): u(u), v(v), w(w) {}
	bool operator<(const edge& rhs) const{
		return w < rhs.w;
	}
}e[M];
int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void work() {
	vector<int> ans;
	for(int i = 0; i < n; i ++) fa[i] = i;

	for(int i = 0; i < m; i ++) {
		int u = find(e[i].u), v = find(e[i].v);
		if(u != v) {
			fa[v] = u;
			continue;
		}
		ans.pb(e[i].w);
	}

	int sz = ans.size();
	if(sz) {
		for(int i = 0; i < sz - 1; i ++) printf("%d ", ans[i]);
		printf("%d\n", ans[sz - 1]);
	} else puts("forest");
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m), n + m) {
    	int u, v, w;
    	for(int i = 0; i < m; i ++) {
    		siii(u, v, w);
    		e[i] = edge(u, v, w);
    	} 
    	sort(e, e + m);
    	work();
    }
    
    return 0;
}