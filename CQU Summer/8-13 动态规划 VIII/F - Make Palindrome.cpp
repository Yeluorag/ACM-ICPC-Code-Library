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
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int len, dp[N][N];
char s[N];

int DP(int l, int r) {
	if(l >= r) return dp[l][r] = 0;
	if(dp[l][r] < inf) return dp[l][r];
	if(s[l] == s[r]) return dp[l][r] = DP(l + 1, r - 1);
	else return dp[l][r] = min(DP(l + 1, r), DP(l, r - 1)) + 1;
}

void dfs(int l, int r) {
	if(l > r) return;
	if(l == r) { putchar(s[l]); return; }
	if(s[l] == s[r]) {
		putchar(s[l]);
		dfs(l + 1, r - 1);
		putchar(s[r]);
	} else if(dp[l+1][r] < dp[l][r-1]) {
		putchar(s[l]);
		dfs(l + 1, r);
		putchar(s[l]);
	} else {
		putchar(s[r]);
		dfs(l, r - 1);
		putchar(s[r]);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(~ss(s)) {
    	len = strlen(s);
    	mem(dp, 0x3f);
    	
    	printf("%d ", DP(0, len - 1));
    	dfs(0, len - 1);
    	ET;
    	
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}