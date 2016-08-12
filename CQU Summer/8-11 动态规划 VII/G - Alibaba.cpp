#define LOCAL
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int n, ans, pos, a[N], t[N], dp[N][N][2], flag[N];

void init() {
	mem(dp, 0x3f); 
	pos = 0; ans = inf;
	rep(i, n) dp[i][i][0] = dp[i][i][1] = 0;
}

void solve() {
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

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n) != EOF) {
    	rep(i, n) sii(a[i], t[i]);
    	init();
    	solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}