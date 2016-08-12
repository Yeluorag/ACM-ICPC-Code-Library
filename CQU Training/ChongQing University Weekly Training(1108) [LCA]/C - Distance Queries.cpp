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
const int inf = 0x3f3f3f3f, N = 4e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ne;
struct edge {
    int v, w, next;
}e[4 * N];
int head[N], dis[N], ans[N], vis[N], fa[N];
vector<pair<int, int> > query[N];

void addEdge(int u, int v, int w) {
    e[ne].v = v, e[ne].next = head[u], e[ne].w = w, head[u] = ne ++;
    e[ne].v = u, e[ne].next = head[v], e[ne].w = w, head[v] = ne ++;
}

int find(int x) {
    if(x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}

void Tarjan(int u, int d) {
    fa[u] = u;
    dis[u] = d;
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v, w = e[i].w;
        if(!vis[v]) {
            Tarjan(v, d + w);
            fa[v] = u;
        }
    }
    
    int len = query[u].size();
    rep(i, len) {
        int v = query[u][i].first, w = query[u][i].second;
        if(vis[v]) ans[w] = dis[u] + dis[v] - 2 * dis[find(v)];
    }
}
void init() {
    mem(head, -1);
    mem(vis, 0);
    mem(ans, 0);
    mem(dis, 0);
    ne = 0;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(n, m) != EOF) {
        init();
        int u, v, w;
        char c;
        rep(i, m) {
            scanf("%d %d %d %c", &u, &v, &w, &c);
            addEdge(u, v, w);
        }
        si(m);
        rep(i, m) {
            sii(u, v);
            query[u].pb(make_pair(v, i));
            query[v].pb(make_pair(u, i));
        }
        Tarjan(1, 0);
        rep(i, m) printf("%d\n", ans[i]);
    }
    
    return 0;
}