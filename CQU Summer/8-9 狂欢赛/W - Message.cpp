#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 2e3 + 5, MOD = 1e9 + 7;

int n, m, dp[N][N];
char s[N], u[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    mem(dp, 0);
    ss(s); ss(u);
    n = strlen(s);
    m = strlen(u);
    rep(i, n) {
        rep(j, m) {
            if(s[i] == u[j]) dp[i+1][j+1] = dp[i][j] +1;
            else dp[i+1][j+1] = dp[i][j];
        }
    }
    int ans = 0;
    FOR(i, 0, n) FOR(j, 0, m) ans = max(ans, dp[i][j]);
    printf("%d\n", m - ans);
    return 0;
}