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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int d[N][N],u, v, n, vis[N];
VI t;

void read() {
    mem(d, 0x3f);
    mem(vis, 0);
    t.clear();

    vis[u] = vis[v] = 1;
    d[u][v] = 1, Max(n, max(u, v));
    
    while(sii(u, v), u + v) d[u][v] = 1, vis[u] = vis[v] = 1, Max(n, max(u, v));
    rep(i, N) if(vis[i]) t.pb(i);
    n = t.size();
}

void floyd() {
    rep(k, n)rep(i, n) rep(j, n)
    Min(d[t[i]][t[j]], d[t[i]][t[k]] + d[t[k]][t[j]]);
}

void solve() {
    read(), floyd();
    int ans = 0;

    rep(i, n) rep(j, n) if(t[i] != t[j] && d[t[i]][t[j]] != inf) 
    ans += d[t[i]][t[j]];

    double ret = (double)ans / (double)(n * (n - 1));
    printf("Case %d: average length between pages = %.3lf clicks\n", ++ cas, ret);
}



//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(~sii(u, v), u + v) solve();
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}