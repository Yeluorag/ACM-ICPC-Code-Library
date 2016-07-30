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
int n, m, t, s;
int dp[N][N], w[N], v[N];
// Imp
void tpe0(int i) {
	rep(k, m) {
		for(int j = t; j >= w[k]; j --) {
			if(dp[i][j-w[k]] != -1) Max(dp[i][j], dp[i][j-w[k]] + v[k]);	//至少选1个
			if(dp[i-1][j-w[k]] != -1) Max(dp[i][j], dp[i-1][j-w[k]] + v[k]);//带上之前的找到最优解
		}
	}
}
void tpe1(int i) {
	FOR(j, 0, t) dp[i][j] = dp[i-1][j];
	rep(k, m) {
		for(int j = t; j >= w[k]; j --) {
			if(dp[i-1][j-w[k]] != -1)
				Max(dp[i][j], dp[i-1][j-w[k]] + v[k]);	//不可包含当前组的前置状态
		}
	}
}
void tpe2(int i) {
	FOR(j, 0, t) dp[i][j] = dp[i-1][j];
	rep(k, m) {
		for(int j = t; j >= w[k]; j --) {
			if(dp[i][j-w[k]] != -1)
				Max(dp[i][j], dp[i][j - w[k]] + v[k]);	//01背包
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, t) != EOF) {
    	mem(dp, -1);
    	mem(dp[0], 0);
    	FOR(i, 1, n) {
    		sii(m, s);
    		rep(j, m) sii(w[i], v[i]);
    		switch(s) {
    			case 0: tpe0(i); break;
    			case 1: tpe1(i); break;
    			case 2: tpe2(i); break;
    			default: break;
    		}
    	}
    	printf("%d\n", dp[n][t]);
    }
    
    
    return 0;
}