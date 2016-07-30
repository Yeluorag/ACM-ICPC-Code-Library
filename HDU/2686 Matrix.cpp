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
#define Max(b, c, d, e) max(max(b, c), max(d, e))
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 30 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N][N], dp[65][N][N];
bool check(int x1, int x2) {
    return x1 >= 0 && x2 >= 0 && x1 != x2;
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(si(n) != EOF) {
        mem(a, 0);
        mem(dp, 0);
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) si(a[i][j]);
        for(int cnt = 1; cnt <= 2 * n - 2; cnt ++) {
            for(int x1 = 0; x1 <= cnt; x1 ++) {
                for(int x2 = 0; x2 <= cnt; x2 ++) {
                    int y1 = cnt - x1, y2 = cnt - x2;
                    int& ret = dp[cnt][x1][x2];
                    if(check(x1, x2)) ret = max(ret, dp[cnt-1][x1][x2]);
                    if(check(x1 - 1, x2)) ret = max(ret, dp[cnt-1][x1-1][x2]);
                    if(check(x1, x2 - 1)) ret = max(ret, dp[cnt-1][x1][x2-1]);
                    if(check(x1 - 1, x2 - 1)) ret = max(ret, dp[cnt-1][x1-1][x2-1]);
                    ret += a[x1][y1] + a[x2][y2];
                }
            }
        }
        printf("%d\n", dp[2*n-2][n-1][n-1] + a[0][0] - a[n-1][n-1]);
    }
    
    return 0;
}