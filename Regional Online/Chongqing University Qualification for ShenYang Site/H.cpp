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
const int inf = 0x7f7f7f7f, N = 1e2 + 5, MOD = 1e9 + 7;
const double tmp = (1.0 + sqrt(5)) / 2.0;
const int M = 2e4 + 5;
int T, cas = 0;
int n, m, f;
int t[N], c[N], a[N];
double dp[M];

double dfs(int f) {
	if(dp[f] > 0) return dp[f];
	rep(i, n) {
		if(f > c[i]) dp[f] += t[i] * 1.0 / n;
		else dp[f] += (1.0 + dfs(f + c[i])) / n;
	}
	return dp[f];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, f) != EOF) {
    	mem(dp, 0);
    	rep(i, n) si(c[i]);
    	sort(c, c + n);
    	rep(i, n) t[i] = floor(tmp * c[i] * c[i]);
    	printf("%.3lf\n", dfs(f));    	
    }
    
    return 0;     
}