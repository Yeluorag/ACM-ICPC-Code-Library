// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int ans, now;
int a[N], t[N], dp[N][N][2], flag[N];

// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	rep(i, n) sii(a[i], t[i]);
    	mem(dp, 0x3f); 
		ans = inf;
		rep(i, n) dp[i][i][0] = dp[i][i][1] = 0;
		for(int i = n - 1; i >= 0; i --) {
			REP(j, i, n) {
				int &ret1 = dp[i-1][j][0], &ret2 = dp[i][j+1][1];
				int &tmp1 = dp[i][j][0], &tmp2 = dp[i][j][1];

				if(i && tmp1 + a[i] - a[i-1] < t[i-1]) 		   ret1 = min(ret1, tmp1 + a[i] - a[i-1]);
				if(j < n - 1 && tmp1 + a[j+1] - a[i] < t[j+1]) ret2 = min(ret2, tmp1 + a[j+1] - a[i]);
				if(i && tmp2 + a[j] - a[i-1] < t[i-1]) 		   ret1 = min(ret1, tmp2 + a[j] - a[i-1]);
				if(j < n - 1 && tmp2 + a[j+1] - a[j] < t[j+1]) ret2 = min(ret2, tmp2 + a[j+1] - a[j]);
	   		}
    	}
	    ans = min(dp[0][n-1][0], dp[0][n-1][1]);
	    if(ans < inf) printf("%d\n", ans);
	    else puts("No solution");
	}
    
    return 0;
}