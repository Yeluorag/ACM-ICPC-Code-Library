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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int a[N], b[N], w[N], dp[2][N], vis[N];

// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        mem(dp, 0);
        sii(m, n);
        FOR(i, 1, n) siii(w[i], a[i], b[i]);
        FOR(i, 1, n) {
            for(int j = 0; j <= m; j ++) {
                Max(dp[0][j], dp[1][j]);
                if(j >= w[i]) dp[1][j] = max(dp[0][j-w[i]] + a[i] + b[i], dp[1][j-w[i]] + a[i]);
            }
        }
        put(max(dp[0][m], dp[1][m]));
    }
    
    return 0;
}