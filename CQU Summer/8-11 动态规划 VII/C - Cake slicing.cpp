#define LOCAL
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
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 25, MOD = 1e9 + 7;

int T, cas = 0;
int m, n, k;
int dp[N][N][N][N];
int a[N][N];

void Mem() { mem(a, 0); mem(dp, -1); }

int dfs(int sx, int sy, int ex, int ey) {
    int& ret = dp[sx][sy][ex][ey];
    if(ret != -1) return ret;
    int cnt = 0;
    FOR(i, sx, ex) FOR(j, sy, ey) cnt += a[i][j];
    if(cnt == 1) return ret = 0;
    if(cnt == 0) return ret = inf;
    ret = inf;
    REP(i, sx, ex) ret = min(ret, dfs(sx, sy, i, ey) + dfs(i + 1, sy, ex, ey) + ey - sy + 1);
    
    REP(i, sy, ey) ret = min(ret, dfs(sx, sy, ex, i) + dfs(sx, i + 1, ex, ey) + ex - sx + 1);
    
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(siii(n, m, k) != EOF) {
        int x, y;
        Mem();
        rep(i, k) sii(x, y), a[x][y] = 1;
        int ans = dfs(1, 1, n, m);
        printf("Case %d: %d\n", ++ cas, ans);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}