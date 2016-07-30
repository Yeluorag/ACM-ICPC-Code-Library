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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N], a[N], sum[N];
/*
int dfs(int i, int j) {
	int& ret = dp[i][j];
	if(ret != -1) return ret;
	int tmp = 0;
	for(int k = i; k < j; k ++)
		tmp = min(tmp, min(dfs(i, k), dfs(k + 1, j)));
	return ret = sum[j] - sum[i-1] - tmp;
}
*/

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n), n) {
    	mem(sum, 0);
    	mem(dp, 0);
    	for(int i = 1; i <= n; i ++) si(a[i]), sum[i] = sum[i-1] + a[i];
    	for(int i = 1; i <= n; i ++) dp[i][i] = a[i];

    	for(int l = 2; l <= n; l ++) {
    		for(int i = 1; i < n; i ++) {
    			int j = i + l - 1;
    			for(int k = i; k < j; k ++)
    				dp[i][j] = min(dp[i][j], min(dp[i][k], dp[k+1][j]));
    			dp[i][j] = sum[j] - sum[i-1] - dp[i][j];
    		}
    	}
    	// dfs(1, n);
    	printf("%d\n", 2 * dp[1][n] - sum[n]);
    }
    
    return 0;
}