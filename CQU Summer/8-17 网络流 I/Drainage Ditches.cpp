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
const int inf = 0x3f3f3f3f, N = 2e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int s, e;
int pre[N], g[N][N];
bool vis[N];

// Imp


bool bfs() {
    queue<int> que;
    mem(pre, 0);
    mem(vis, 0);
    vis[s] = 1;
    que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        if(u == e) return true;
        FOR(i, 1, n) {
            if(!vis[i] && g[u][i]) {
                que.push(i);
                pre[i] = u;
                vis[i] = 1;
            }
        }
    }
    return false;
}

int MaxFlow() {
    int flow = 0;
    while(true) {
        if(!bfs()) return flow;
        
        int tmp = inf;
        for(int i = e; i != s; i = pre[i])
            Min(tmp, g[pre[i]][i]);
        for(int i = e; i != s; i = pre[i]) {
            g[pre[i]][i] -= tmp;
            g[i][pre[i]] += tmp;
        }
        flow += tmp;
        
    }
    return flow;
}

void read() {
    int u, v, f;
    s = 1, e = n;
    mem(g, 0);
    rep(i, m) {
        siii(u, v, f);
        g[u][v] += f;
    }
}

void solve() {
    read();
    put(MaxFlow());
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    
    // si(T); while(T --) solve();
    // while(~si(n), n) solve();
    while(sii(m, n) != EOF) solve();
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}