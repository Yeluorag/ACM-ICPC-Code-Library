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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const double INF = 1.0 * (1 << 30);

int n, m, v, x, sum[N];
double dp[N][N][2];
struct node{
    int x, c, d;
    node(int a = 0, int cost = 0, int b = 0): x(a), c(cost), d(b) {}
    bool operator<(const node &t) const { return x < t.x; }
}a[N];
void solve() {
    for(int i = m; i >= 0; i --) {
        for(int j = m; j <= n; j ++) {
            double &ret1 = dp[i-1][j][0], &ret2 = dp[i][j+1][1];
            double &tmp1 = dp[i][j][0], &tmp2 = dp[i][j][1];
            double k = sum[i-1] + sum[n] - sum[j], t, g;
            if(i){
                t = 1.0 * (a[i].x - a[i-1].x) / v;
                g = tmp1 + a[i-1].c + k * t;
                Min(ret1, g);
            
                t = 1.0 * (a[j].x - a[i-1].x) / v;
                g = tmp2 + a[i-1].c + k * t;
                Min(ret1, g);
            }
            if(j != n) {
                t = 1.0 * (a[j+1].x - a[i].x) / v;
                g = tmp1 + a[j+1].c + k * t;
                Min(ret2, g);
                
                t = 1.0 * (a[j+1].x - a[j].x) / v;
                g = tmp2 + a[j+1].c + k * t;
                Min(ret2, g);
            }
        }
    }
    int ans = min(dp[0][n][0], dp[0][n][1]);
    printf("%d\n", ans);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(~siii(n, v, x) && (n + v + x)) {
        rep(i, n) siii(a[i].x, a[i].c, a[i].d);
        a[n].x = x, a[n].c =0, a[n].d = 0;
        sort(a, a + n + 1);
        m = lower_bound(a, a + n + 1, node(x, 0, 0)) - a;
        sum[0] = a[0].d;
        FOR(i, 1, n) sum[i] = sum[i-1] + a[i].d;
        FOR(i, 0, n + 1) FOR(j, i, n + 1)
        dp[i][j][0] = dp[i][j][1] = INF;
        dp[m][m][0] = dp[m][m][1] = 0;
        solve();
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}