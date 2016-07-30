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
const int inf = 0x3f3f3f3f, N = 3e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int x[N], d[N][N], dp[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	for(int i = 1; i <= n; i ++) scanf("%d", &x[i]);
    	mem(dp, 0x3f);
    	mem(d, 0);
    	for(int i = 1; i <= n; i ++) {
    		for(int j = i + 1; j <= n; j ++) {
    			d[i][j] = d[i][j-1] + x[j] - x[(i + j) / 2]; 
    		}
    	}
    	for(int i = 1; i <= n; i ++) dp[i][i] = 0, dp[i][1] = d[1][i];
    	for(int j = 2; j <= m; j ++) {
    		for(int i = j + 1; i <= n ; i ++) {
    			for(int k = j; k < i; k ++) {
    				dp[i][j] = min(dp[i][j], dp[k][j-1] + d[k+1][i]);
    			}
    		}
    	}
    	printf("%d\n", dp[n][m]);
    }
    
    return 0;
}