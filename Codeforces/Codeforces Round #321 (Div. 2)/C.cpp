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
int n, m, ans = 0;
int a[N];
bool vis[N];
// Imp
vector<int> son[N];

void dfs(int u, int cnt) {
    int sz = son[u].size();
    if(cnt > m) return;
    if(!a[u]) cnt = 0;
    if(sz == 1 && u != 1) ans ++;
    rep(i, sz) {
        int v = son[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, cnt + a[v]);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    sii(n, m);
    rep(i, n) si(a[i + 1]);
    rep(i, n - 1) {
        int u, v;
        sii(u, v);
        son[u].pb(v);
        son[v].pb(u);
    }
    mem(vis, 0);
    vis[1] = 1;
    dfs(1, a[1]);
    printf("%d\n",ans);
    return 0;
}