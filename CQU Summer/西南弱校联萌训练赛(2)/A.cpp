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
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, k, dp[N];
int p[N];
VI son[N];
// Imp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
LL lcm(int a, int b) {
    return ((LL)a * (LL)b / (LL)gcd(a, b)) % MOD;
}
int dfs(int u, int x) {
    if(k % x) return 0;
    if(x == k && u == n) return dp[u] = 1;
    if(dp[u] > -1) return dp[u];
    dp[u] = 0;
    int sz = son[u].size();
    rep(i, sz) {
        int v = son[u][i];
        LL tmp = lcm(x, p[v]);
        if(tmp == x || k % tmp > 0) continue;
        dp[u] += dfs(v, tmp);
        dp[u] %= MOD;
    }
    return dp[u];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(siii(n, m, k) != EOF) {
        int u, v;
        mem(dp, -1);
        rep(i, N) son[i].clear();
        rep(i, m) {
            sii(u, v);
            son[u].pb(v);
        }
        FOR(i, 1, n) si(p[i]);
        int ans = dfs(1, p[1]);
        put(ans);
    }
    
    return 0;
}