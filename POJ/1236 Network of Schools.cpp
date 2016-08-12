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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct edge {
    int v, next;
}e[N * N];
int dfn[N], low[N], in[N], out[N], head[N], g[N], st[N], vis[N];
int ne = 0, ans = 0, dfsNum = 0, tot = 0, top = 0, ans1, ans2;
void addEdge(int u, int v) {
    e[ne].v = v;
    e[ne].next = head[u];
    head[u] = ne ++;
}
// Imp
void init() {
    mem(dfn, 0);
    mem(low, 0);
    mem(in, 0);
    mem(out, 0);
    mem(st, 0);
    mem(vis, 0);
    mem(head, -1);
    dfsNum = ne = top = tot = 0;
}

void Tarjan(int u) {
    dfn[u] = low[u] = ++ dfsNum;
    st[top++] = u;
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(!dfn[v]) {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    
    if(low[u] == dfn[u]) {
        tot ++;
        while(1) {
            int k = st[--top];
            g[k] = tot;
            vis[k] = 0;
            if(k == u) break;
        }
    }
}

void work() {
    ans1 = ans2 = 0;
    FOR(u, 1, n) {
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(g[u] == g[v]) continue;
            out[g[u]] ++;
            in[g[v]] ++;
        }
    }
}

void Gao() {
    work();
    FOR(i, 1, tot) {
        if(!in[i]) ans1 ++;
        if(!out[i]) ans2 ++;
    }
    
    if(tot == 1) printf("1\n0\n");
    else printf("%d\n%d\n", ans1, max(ans1, ans2));
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(n);
    int v;
    init();
    FOR(u, 1, n) while(si(v), v) addEdge(u, v);
    FOR(i, 1, n) if(!dfn[i]) Tarjan(i);
    Gao();
    
    return 0;
}