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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int tot, s, t;
int head[N], nxt[N], cost[N], a[N], b[N], pnt[N], d[N];
bool vis[N];
queue<int> que;
// Imp

void AddEdge(int u, int v, int c, int sa, int sb) {
    pnt[tot] = v, nxt[tot] = head[u], cost[tot] = c;
    a[tot] = sa, b[tot] = sb;
    head[u] = tot ++;
}

void init() {
    tot = 0;
    mem(head, -1);
    rep(i, m) {
        int u, v, a, b, t;
        scanf("%d%d%d%d%d", &u, &v, &a, &b, &t);
        if(a >= t) AddEdge(u, v, a, b, t);
    }
}

int Spfa(int st, int des) {
    mem(d, 0x3f);
    mem(vis, 0);
    d[st] = 0;
    que.push(st);
    
    while(!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = 0;
        for(int i = head[u]; i != -1; i = nxt[i]) {
            int v = pnt[i], val = d[u], tmp = d[u];
            val = val % (a[i] + b[i]);
            if(val > a[i]) tmp += a[i] + b[i] - val;
            else if(a[i] - val < cost[i]) tmp += a[i] + b[i] - val;
            if(tmp + cost[i] < d[v]) {
                d[v] = tmp + cost[i];
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return d[des];
}

void solve() {
    init();
    printf("Case %d: %d\n", ++ cas, Spfa(s, t));
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    
    // si(T); while(T --) solve();
    // while(~si(n), n) solve();
    // while(~sii(n, m), n + m) solve();
    while(~scanf("%d%d%d%d", &n, &m, &s, &t)) solve();
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
