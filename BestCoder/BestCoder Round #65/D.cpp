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
const int inf = 0x3f3f3f3f, N = 5e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, a, b, k;
int dp[N][11], f[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, k); sii(a, b);
    	mem(dp, 0);
    	f[1] = 0;
    	dp[1][0] = 1;
    	for(LL i = 2; i <= n; i ++) {
    		f[i] = ((LL)a * (LL)i + (LL)b) % (i - 1) + 1;
    		dp[i][0] = 1;
    		for(int j = 1; j <= k; j ++) {
    			dp[i][j] = dp[f[i]][j-1];
    			dp[f[i]][1] ++;
    		}
    	}
    	int ans = 0;
    	for(int i = 1; i <= n; i ++) {
    		int cnt = 0;
    		for(int j = 0; j <= k; j ++){
    			cnt += dp[i][j];
    		}
    		ans ^= cnt;
    	}
    	printf("%d\n", ans);
    }
    
    return 0;
}