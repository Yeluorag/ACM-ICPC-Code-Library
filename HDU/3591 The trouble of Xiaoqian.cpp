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
const int inf = 1e8, N = 2e4 + 5, MOD = 1e9 + 7;
const int M = 2e4;
// Macro end

int T, cas = 0;
int n, m, t;
int dp1[N], dp2[N], c[105], v[105];

// Imp
// Use Last Group
void ZeroOne_Pack(int weight, int value, int m, int dp[], int k) {
    for(int i = m; i >= weight; i --)
        dp[i] = min(dp[i], dp[i-weight] + k);
}
// Use This Group
void Complete_Pack(int weight, int value, int m, int dp[], int k) {
    for(int i = weight; i <= m; i ++)
        dp[i] = min(dp[i], dp[i-weight] + k);
}
// n: Number of Group, m: Total Weight of Pack
int Multi_Pack(int w[], int v[], int num[], int n, int m, int dp[]) {
    for(int i = 1; i <= n; i ++) {
        if(num[i] * w[i] > m)
            Complete_Pack(w[i], v[i], m, dp, 1);
        else {
            for(int k = 1; k < num[i]; k *= 2) {
                ZeroOne_Pack(k * w[i], k * v[i], m, dp, k);
                num[i] -= k;
            }
            ZeroOne_Pack(num[i] * w[i], num[i] * v[i], m, dp, num[i]);
        }
    }
    return dp[m];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(n, t), n + t) {
        rep(i, N) dp1[i] = dp2[i] = inf;
        int ans = inf;
        dp1[0] = dp2[0] = 0;
        FOR(i, 1, n) si(v[i]);
        FOR(i, 1, n) si(c[i]);
        dp1[M] = Multi_Pack(v, v, c, n, M, dp1);
        FOR(i, 1, n) Complete_Pack(v[i], v[i], M, dp2, 1);
        FOR(i, t, M) Min(ans, dp1[i] + dp2[i-t]);
        if(ans == inf) ans = -1;
        printf("Case %d: %d\n", ++ cas, ans);
    }
    
    return 0;
}