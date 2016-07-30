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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, w, k;
int dp[N][N], y[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	si(T);
	while(T --) {
		mem(dp, 0);
		siii(n, w, k);
		for(int i = 1; i <= n; i ++) scanf("%*d%d", &y[i]);
		sort(y + 1, y + n + 1);
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = i; j <= n; j ++)
				dp[i][1] += y[j] - y[i] <= w;
			ans = max(ans, dp[i][1]);
		}
		
		for(int i = 1; i <= n; i ++) {
			for(int l = 2; l <= min(i, k); l ++) {
				for(int j = 1; j < i; j ++) {
					if(y[i] - y[j] > w) dp[i][l] = max(dp[i][l], dp[j][l-1] + dp[i][1]);
				}
				ans = max(ans, dp[i][l]);
			}
		}
		printf("Case %d: %d\n", ++ cas, ans);
	}
    
    
    return 0;
}