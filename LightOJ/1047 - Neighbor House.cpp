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
const int inf = 0x3f3f3f3f, N = 20 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int r[N], g[N], b[N];
int dp[N][3][3];  // dp[i][now][last]

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	mem(dp, 0x3f);
    	r[0] = g[0] = b[0] = 0;
    	mem(dp, 0x3f);
    	mem(dp[0], 0);
    	for(int i = 1; i <= n; i ++) siii(r[i], g[i], b[i]);
    	for(int i = 1; i <= n; i ++) {
    		dp[i][0][1] = min(dp[i-1][1][0], dp[i-1][1][2]) + r[i];
    		dp[i][0][2] = min(dp[i-1][2][0], dp[i-1][2][1]) + r[i];

    		dp[i][1][0] = min(dp[i-1][0][1], dp[i-1][0][2]) + g[i];
    		dp[i][1][2] = min(dp[i-1][2][0], dp[i-1][2][1]) + g[i];

    		dp[i][2][0] = min(dp[i-1][0][1], dp[i-1][0][2]) + b[i];
    		dp[i][2][1] = min(dp[i-1][1][0], dp[i-1][1][2]) + b[i];
    	}
    	int ans = inf;
    	for(int i = 0; i < 3; i ++) for(int j = 0; j < 3; j ++) ans = min(ans, dp[n][i][j]);
    	printf("Case %d: %d\n", ++ cas, ans);
    }
    
    return 0;
}