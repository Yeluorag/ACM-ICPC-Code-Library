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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N][N], dp[2 * N][N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
        sii(n, m);
        for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) si(a[i][j]);
        mem(dp, -1);
        
        for(int i = 1; i < n + m; i ++) {
            for(int x1 = 1; x1 <= i && x1 <= n; x1 ++) {
                for(int x2 = 1; x2 <= i && x2 <= n; x2 ++) {
                    if(i == 1) {
                        dp[1][1][1] = a[1][1];
                        continue;
                    }
                    if(x1 == x2 && i < n + m - 1) continue;
                    int y1 = i + 1 - x1, y2 = i + 1 - x2;
                    if(y1 > m || y2 > m) continue;
                    int& ret = dp[i][x1][x2];
                    if(i > x1 && i > x2) ret = max(ret, dp[i-1][x1][x2]);
                    if(i > x1 && x2 > 1) ret = max(ret, dp[i-1][x1][x2-1]);
                    if(i > x2 && x1 > 1) ret = max(ret, dp[i-1][x1-1][x2]);
                    if(x1 > 1 && x2 > 1) ret = max(ret, dp[i-1][x1-1][x2-1]);
                    ret += a[x1][y1] + a[x2][y2];
                }
            }   
        }
        printf("Case %d: %d\n", ++ cas, dp[n+m-1][n][n] - a[n][m]);
    }
    
    return 0;
}
