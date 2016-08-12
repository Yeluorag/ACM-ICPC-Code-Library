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
const int inf = 1 << 30, N = 1e2 + 5, MOD = 1e4;

int T, cas = 0;
int n, m, a[N][N], dp[N][N];

int dfs(int r, int c) {
    if(dp[r][c] >= 0) return dp[r][c];
    int ret = 0;
    if(r == 1 && c == 1) return 1;
    FOR(i, 1, r) {
        FOR(j, 1, c) {
            if(i == r && j == c) continue;
            if(r + c - i - j <= a[i][j]){
                ret += dfs(i, j);
                ret %= MOD;
            }
        }
    }
    dp[r][c] = ret;
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        sii(n, m);
        FOR(i, 1, n) FOR(j, 1, m) si(a[i][j]);
        mem(dp, -1);
        int ans = dfs(n, m);
        printf("%d\n", dp[n][m]);
    }
    
    return 0;
}