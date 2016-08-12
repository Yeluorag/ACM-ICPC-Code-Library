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
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 1e4 + 5, MOD = 1e9 + 7;

int n, flag, a[N], dp[N];

void solve() {
	int l = 0, r = 0, lt = 0, rt = 0, ans = dp[0];
	rep(i, n) {
		if(dp[i] < 0) lt = i + 1;
		if(dp[i] >= 0) rt = i;
		if(dp[i] > ans) { l = lt; r = rt; ans = dp[i]; }
	}
	if(flag) { l = 0; r = n - 1; ans = 0;}
	printf("%d %d %d\n",ans, a[l], a[r]);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n), n) {
    	mem(dp, 0);
    	flag = 1;
    	rep(i, n) {
    		si(a[i]);
    		if(a[i] >= 0) flag = 0;
    		dp[i] = a[i];
			if(i && dp[i-1] > 0) dp[i] += dp[i-1];
    	}
    	solve();
    }
    
    return 0;
}