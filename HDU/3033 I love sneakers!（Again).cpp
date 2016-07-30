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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, K;
int dp[11][10005];
VI w[11], v[11];
// Imp

void init() {
	FOR(i, 1, K) {
		int sz = w[i].size();
		rep(k, sz) {
			for(int j = m; j >= w[i][k]; j --) {
				if(dp[i][j] != -1) Max(dp[i][j], dp[i][j-w[i][k]] + v[i][k]);
				if(dp[i-1][j] != -1) Max(dp[i][j], dp[i-1][j-w[i][k]] + v[i][k]);
			}
		}	
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	int a, b, c;
    while(siii(n, m, K) != EOF) {
    	mem(dp, -1);
    	mem(dp[0], 0);
    	rep(i, 11) w[i].clear(), v[i].clear();
    	
    	rep(i, n) {
    		siii(a, b, c);
    		w[a].pb(b);
    		v[a].pb(c);
    	}
    	init();
    	if(dp[K][m] == -1) puts("Impossible");
    	else put(dp[K][m]);
    }
    
    return 0;
}