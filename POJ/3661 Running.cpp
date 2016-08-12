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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int d[N], dp[N][505];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	for(int i = 1; i <= n; i ++) si(d[i]);
    	mem(dp, 0);
    	for(int i = 1; i <= n; i ++) {
    		dp[i][0] = dp[i-1][0];
    		for(int k = 1; k <= min(i, m); k ++) dp[i][0] = max(dp[i][0], dp[i-k][k]);
    		for(int j = 1; j <= m; j ++)  dp[i][j] = dp[i-1][j-1] + d[i];
    	}
    	printf("%d\n", dp[n][0]);
    }
    
    return 0;
}