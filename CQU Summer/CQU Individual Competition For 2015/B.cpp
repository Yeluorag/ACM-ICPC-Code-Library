// Header.
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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 100000007;

int T, cas = 0;
int n, m;
int dp[N][2*N][2];
// Imp
void init() {
    mem(dp, 0);
    dp[1][1][1] = 1;
    dp[1][2][0] = 1;
    REP(i, 1, N - 2) {
        REP(k, 1, 2 * N - 2) {
            if(k > 2 * i) continue;
            dp[i+1][k][0] = (dp[i+1][k][0] + dp[i][k][0]) % MOD;
            dp[i+1][k+1][0] = (dp[i+1][k+1][0] + 2 * dp[i][k][0] + 2 * dp[i][k][1]) % MOD;
            dp[i+1][k+2][0] = (dp[i+1][k+2][0] + dp[i][k][0] + dp[i][k][1]) % MOD;
            
            dp[i+1][k][1] = (dp[i+1][k][1] + 2 * dp[i][k][0] + dp[i][k][1]) % MOD;
            dp[i+1][k+1][1] = (dp[i+1][k+1][1] + dp[i][k][0] + dp[i][k][1]) % MOD;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    si(T);
    while(T --) {
        sii(n, m);
        int ans = (dp[n][m][0] + dp[n][m][1]) % MOD;
        printf("%d\n", ans);
    }
    
    return 0;
}