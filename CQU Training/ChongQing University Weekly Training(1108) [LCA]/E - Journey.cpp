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
#define mem(a, n) memset(a, n, sizeof a)
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 2e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ne, tot;
struct edge {
    int v, w, next;
}e[N];
struct query {
    int u, v, w;
    int id, next;
}q[3 * N];
int head[N], dis[N], fa[N], h[3 * N];
bool vis[N], f[N];

void addEdge(int u, int v, int w) {
    e[ne].v = v, e[ne].w = w, e[ne].next = head[u];
    head[u] = ne ++;
    e[ne].v = u, e[ne].w = w, e[ne].next = head[v];
    head[v] = ne ++;
}

void addQuery(int u, int v, int i) {
    q[tot].u = u, q[tot].v = v, q[tot].next = h[u];
    q[tot].id = i, h[u] = tot ++;
    q[tot].u = v, q[tot].v = u, q[tot].next = h[v];
    q[tot].id = i, h[v] = tot ++;
}

void init() {
    mem(dis, 0);
    mem(fa, 0);
    mem(vis, false);
    mem(f, false);
    mem(head, -1);
    mem(h, -1);
    FOR(i, 1, n) fa[i] = i;
    ne = tot = 0;
}

int Find(int x) {
    if(x != fa[x]) return fa[x] = Find(fa[x]);
    return x;
}

void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if(x != y) fa[y] = x;
}

void Tarjan(int u) {
    fa[u] = u;
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(!vis[v]) {
            dis[v] = dis[u] + e[i].w;
            Tarjan(v);
            Union(u, v);
            f[Find(u)] = u;
        }
    }
    for(int i = h[u]; i != -1; i = q[i].next) {
        int v = q[i].v;
        if(vis[v]) q[i^1].w = q[i].w = dis[u] + dis[v] - 2 * dis[Find(v)];
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
        int x, y;
        rep(i, n) {
            siii(u, v, w);
            if(i == n - 1) continue;
            addEdge(u, v, w);
        }
        rep(i, m) {
            sii(x, y);
            addQuery(x, y, i);
            addQuery(x, u, i);
            addQuery(y, v, i);
            addQuery(x, v, i);
            addQuery(y, u, i);
        }
        Tarjan(1);
        printf("Case #%d:\n", ++ cas);
        for(int i = 0; i < tot; i += 10) {
            int d1 = q[i].w, d2 = min(q[i+2].w + q[i+4].w, q[i+6].w + q[i+8].w) + w;
            int d = min(d1, d2), ans = 0;
            if(d == d2) ans = d1 - d2;
            printf("%d\n", ans);
        }
    }
    
    return 0;
}