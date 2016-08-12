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
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 1e2, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int c[N][N];

// EK
int Maxflow(int s, int t) {
    int fa[N], min_flow[N], cap[N][N];
    int flow = 0;
    mem(cap, 0);
    while(true) {
        queue<int> que;
        mem(fa, -1);
        fa[s] = -2;
        min_flow[s] = inf;
        que.push(s);
        while(!que.empty()) {
            int u = que.front(); que.pop();
            rep(v, 2 * n) {
                if(fa[v] == -1 && cap[u][v] < c[u][v]) {
                    que.push(v);
                    fa[v] = u;
                    min_flow[v] = min(min_flow[u], c[u][v] - cap[u][v]);
                }
            }
            if(fa[t] != -1) {
                int k = t;
                while(fa[k] >= 0) {
                    cap[fa[k]][k] += min_flow[t];
                    cap[k][fa[k]] -= min_flow[t];
                    k = fa[k];
                }
                break;
            }
        }
        if(fa[t] == -1) break;
        flow += min_flow[t];
    }
    return flow;
}
int main(){
    
    while(sii(n, m) != EOF) {
        mem(c, 0);
        int u, v;
        rep(i, n) c[i][i+n] = c[i+n][i] = 1;
        rep(i, m) {
            scanf(" (%d,%d)", &u, &v);
            c[u+n][v] = c[v+n][u] = inf;
        }
        int ans = inf;
        REP(i, 1, n) ans = min(ans, Maxflow(n, i));
        if(ans == inf) ans = n;
        printf("%d\n", ans);
    }
    
    return 0;
}