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
int a[N], sum[N];
int dp[N][N];
int min(int a, int b, int c) { return min(a, min(b, c)); }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	mem(dp, 0), mem(sum, 0);
    	for(int i = 1; i <= n; i ++) si(a[i]), sum[i] = sum[i-1] + a[i];
    	for(int j = 1; j <= n; j ++) {
    		for(int i = j; i > 0; i --) {
    			int tmp = 0;
    			for(int k = i; k < j; k ++)
    				tmp = min(tmp, dp[i][k], dp[k+1][j]);
    			dp[i][j] = sum[j] - sum[i-1] - tmp;  
    		}
    	}
    	printf("Case %d: %d\n", ++ cas, 2 * dp[1][n] - sum[n]);
    }

    
    return 0;
}