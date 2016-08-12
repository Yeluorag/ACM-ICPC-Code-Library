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
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
double a[N], b[N], dp[2][105];
void swap() {
	if(n > m) {
		for(int i = 1; i <= n; i ++) swap(a[i], b[i]);
		swap(n, m);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m), n + m) {
    	mem(a, 0), mem(b, 0);
    	for(int i = 1; i <= n; i ++) scanf("%lf", &a[i]);
    	for(int i = 1; i <= m; i ++) scanf("%lf", &b[i]);
    	sort(a + 1, a + 1 + n);
    	sort(b + 1, b + 1 + m);
    	swap();
    	mem(dp, 0x3f);
    	int len = m - n + 1;
    	for(int i = 1; i <= n; i ++) {
    		for(int j = 1; j <= len; j ++) {
    			int k = i + j - 1;
    			dp[i&1][j] = min(dp[(i-1)&1][j] + fabs(a[i] - b[k]), dp[i&1][j-1]);
    		}
    	}
    	printf("%.6f\n", dp[n&1][len]);
    }
    
    return 0;
}