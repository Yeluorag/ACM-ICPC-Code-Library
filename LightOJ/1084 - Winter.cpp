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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k;
int dp[N], a[N];
int dfs(int cur) {
	if(cur >= n) return 0;
	if(dp[cur] != -1) return dp[cur];
	int nxt = upper_bound(a, a + n, a[cur] + k) - a;
	int ret = inf;
	if(nxt - cur >= 3) ret = min(ret, dfs(nxt) + 1);
	if(nxt - cur >= 4) ret = min(ret, dfs(nxt - 1) + 1);
	if(nxt - cur >= 5) ret = min(ret, dfs(nxt - 2) + 1);
	return dp[cur] = ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	si(T);
	while(T --) {
		sii(n, k);
		k = 2 * k;
		for(int i = 0; i < n; i ++) si(a[i]);
		sort(a, a + n);
		mem(dp, -1);
		int ans = dfs(0);
		printf("Case %d: %d\n", ++ cas, ans < inf ? ans : -1);
	}
    
    
    return 0;
}