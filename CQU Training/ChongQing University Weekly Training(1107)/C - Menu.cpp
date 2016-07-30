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
#define rep(i, n) for(int i = 1; i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-5
const int inf = 0x3f3f3f3f, N = 50 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, k;
struct dish {
    int c, v;
}a[N];
double dp[22][N][N][105];
int path[22][N][N][105], ans[22];
void dfs(int i, int j, int l, int w) {
    if(i == 0) return;
    int r = path[i][j][l][w];
    ans[i] = j;
    dfs(i - 1, l, r, w - a[j].c);
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(siii(k, n, m), n + m + k) {
        if(cas ++) puts("");
        for(int i = 1; i <= n; i ++) sii(a[i].c, a[i].v);
        mem(dp, 0);
        rep(i, k) rep(j, n) rep(l, n) {
            for(int w = a[j].c; w <= m; w ++) {
                rep(r, n) {
                    double t = 1.0;
                    if(j == l) {
                        if(l == r) t = 0;
                        else t = 0.5;
                    }
                    if(dp[i][j][l][w] < dp[i-1][l][r][w-a[j].c] + t * a[j].v) {
                        dp[i][j][l][w] = dp[i-1][l][r][w-a[j].c] + t * a[j].v;
                        path[i][j][l][w] = r;
                    }
                }
            }
        }
        
        double ansv = 0.0;
        int b, c, d, e;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                for(int w = 0; w <= m; w ++) {
                    if(dp[k][i][j][w] > ansv) {
                        ansv = dp[k][i][j][w];
                        b = k, c = i, d = j, e = w;
                    } else if(dp[k][i][j][w] == ansv) {
                        if(w < e) { b = k, c = i, d = j, e = w; }
                    }
                }
            }
        }
        dfs(b, c, d, e);
        
        printf("%.1f\n", ansv);
        if(ansv > 0.0) {
            for(int i = 1; i < k; i ++) printf("%d ", ans[i]);
            printf("%d\n", ans[k]);
        }
    }
    
    return 0;
}