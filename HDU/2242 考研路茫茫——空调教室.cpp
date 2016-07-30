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
#define x first
#define y second
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, ne, ans, all, top, bch, dfsNum;
int a[N], head[N], dfn[N], low[N], tree[N], sum[N], col[N], stack[N];
vector<pair<int, int> > brige;
bool vis[N];
struct edge {
    int v, next;
}e[10 * N];
// Imp
void addEdge(int u, int v) {
    e[ne].v = v, e[ne].next = head[u], head[u] = ne ++;
}

void Tarjan(int u, int fa) {
    dfn[u] = low[u] = dfsNum ++;
    vis[u] = 1;
    stack[top++] = u;
    int flag = 0;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa && !flag) { flag = 1; continue; }
        if(!vis[v]) {
            Tarjan(v, u);
            Min(low[u], low[v]);
        } else if(col[v] == -1) Min(low[u], dfn[v]);
        if(dfn[u] < low[v]) brige.pb(make_pair(u, v));
    }
    if(low[u] == dfn[u]) {
        while(stack[top-1] != u) col[stack[--top]] = bch, sum[bch] += a[stack[top]];
        top --;
        sum[bch] += a[stack[top]];
        col[u] = bch ++;
    }
}

void build() {
    int sz = brige.size();
    rep(i, sz) {
        int u = brige[i].x, v = brige[i].y;
        e[ne].v = col[v], e[ne].next = tree[col[u]];
        tree[col[u]] = ne ++;
        e[ne].v = col[u], e[ne].next = tree[col[v]];
        tree[col[v]] = ne ++;
    }
}

int dfs(int u) {
    int tmp = sum[u];
    vis[u] = 1;
    for(int i = tree[u]; i != -1; i = e[i].next) {
        if(!vis[e[i].v]) tmp += dfs(e[i].v);
    }
    Min(ans, abs(all - 2 * tmp));
    return tmp;
}

void init() {
    mem(tree, -1);
    mem(head, -1);
    mem(col, -1);
    mem(vis, 0);
    mem(sum, 0);
    brige.clear();
    bch = top = all = ne = dfsNum = 0;
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(sii(n, m) != EOF) {
        init();
        rep(i, n) si(a[i]), all += a[i];
        int u, v;
        rep(i, m) {
            sii(u, v);
            addEdge(u, v), addEdge(v, u);
        }

        Tarjan(0, 0);

        if(bch != 1) {
            build();
            mem(vis, 0);
            ans = inf;
            dfs(0);
            put(ans);
        } else puts("impossible");
    }
    
    return 0;
}