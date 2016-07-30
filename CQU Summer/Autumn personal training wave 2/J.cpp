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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ne, cnt, q;
struct edge {
	int v, w, next;
}e[4 * N];
int head[N], vis[N], dp[N][2], sum[N], F[N], P[N], rmq[N];

struct SparseTable{
    static const int MaxLength = 2 * N;
    int mm[MaxLength];
    int f[MaxLength][20];
    int (*cp) (int, int);
    
    void build(int *a, int n, int (*func) (int, int)) {
        mm[0] = -1;
        for(int i = 1; i <= n; i ++) {
            mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1]  + 1 : mm[i - 1];
            f[i][0] = i;
        }
        cp = func;
        for(int k = 1; k <= mm[n]; k ++)
            for(int i = 0; i + (1 << k) - 1 <= n; i ++) {
                int len = 1 << (k - 1);
                f[i][k] = func (f[i][k-1], f[i+len][k-1]);
            }
    }
    
    int query(int L, int R) {
        if(L > R) swap(L, R);
        int len = R - L + 1, k = 0;
        while((1 << k) < len) k ++;
        if(k) k --; len = (1 << k);
        return cp(f[L][k], f[R-len+1][k]);
    }
};
inline int MIN(int x, int y) {
	return x < y ? x : y;
}

int GCD(int x, int y) {
	return y == 0? x : GCD(y, x % y);
}
SparseTable minST, gcdST;
inline int MIN(int x, int y) {
	return x < y ? x : y;
}

int GCD(int x, int y) {
	return y == 0? x : GCD(y, x % y);
}
SparseTable st;
// Imp
void init() {
	mem(head, - 1);
	ne = 0;
}
void addEdge(int u, int v, int w) {
	e[ne].v = v, e[ne].w = w, e[ne].next = head[u];
	head[u] = ne ++;
	e[ne].v = u, e[ne].w = w, e[ne].next = head[v];
	head[v] = ne ++;
}
void dfs(int u, int fa, int dfsNum) {
	F[++ cnt] = u;
	P[u] = cnt;
	rmq[cnt] = dfsNum;
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(v == fa) continue;
		sum[cnt + 1] = sum[cnt] + e[i].w;
		dfs(v, u, dfsNum + 1);
		sum[cnt + 1] = sum[cnt] - e[i].w;
		F[++ cnt] = u;
		rmq[cnt] = dfsNum;  
	}
}
void LCA(int root, int node_num) {
	mem(sum, 0);
	cnt = 0;
	dfs(root, root, 0);
	st.build(rmq, 2 * node_num - 1, MIN);
}
int query_lca(int u, int v) {
	return F[st.query(P[u], P[v])];
}

int find(int u, int v) {
	int p = query_lca(u, v);
	return sum[P[v]] + sum[P[u]] - 2 * sum[P[p]];
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif	
	
    si(T);
    while(T --) {
    	init();
    	sii(n, q);
    	int u, v, w;
    	rep(i, n - 1) {
    		siii(u, v, w);
    		addEdge(u, v, w);
    	}
    	siii(u, v, w);
    	LCA(1, n);
    	printf("Case #%d:\n", ++ cas);
    	rep(i, q) {
    		int a, b;
    		sii(a, b);
    		int x = find(a, b), p = min(find(a, u) + find(v, b), find(a, v) + find(u, b)) + w;
    		printf("%d\n", max(x - p, 0));
    	}
    }
    
    return 0;
}