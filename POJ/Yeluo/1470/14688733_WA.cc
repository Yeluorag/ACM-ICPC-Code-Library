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
int n, m, ne;
int head[N], vis[N], ans[N], fa[N], in[N];
VI query[N];
struct node {
    int v, next;
}e[4 * N];
// Imp
void addEdge(int u, int v) {
    e[ne].v = v, e[ne].next = head[u], head[u] = ne ++;
}

int find(int x) {
    if(x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}

void Tarjan(int u) {
    vis[u] = 1;
    fa[u] = u;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(!vis[v]) {
            Tarjan(v);
            fa[v] = u;
        }
    }
    int len = query[u].size();
    rep(i, len) {
        int v = query[u][i];
        if(vis[v]) ans[find(v)] ++;
    }
}

void init() {
    ne = 0;
    mem(in, 0);
    mem(ans, 0);
    mem(vis, 0);
    mem(head, -1);
    rep(i, N) query[i].clear();
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(si(n) != EOF) {
        init();
        int u, v;
        rep(i, n) {
            scanf("%d:(%d) ", &u, &m);
            rep(j, m) si(v), in[v] ++, addEdge(u, v);
        } si(m);
        rep(i, m) {
            while(getchar() != '(');
            scanf("%d %d", &u, &v);
            query[u].pb(v);
        } while(getchar() != ')');
        FOR(i, 1, n) if(!in[i]) {
            Tarjan(i);
            break;
        }
        FOR(i, 1, n) if(ans[i]) printf("%d:%d\n", i, ans[i]);
    }
    
    return 0;
}