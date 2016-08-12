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
const int inf = 0x3f3f3f3f, N = 2e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N][N], dp[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	mem(dp, 0), mem(a, 0);
    	FOR(i, 1, n) FOR(j, 1, i) si(a[i][j]);
    	FOR(i, n + 1, 2 * n - 1) FOR(j, 1, 2 * n - i) si(a[i][j]);
    	FOR(i, 1, 2 * n - 1) {
    		if(i <= n) FOR(j, 1, i) dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
    		else FOR(j, 1, 2 * n - i) dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + a[i][j];
    	}
    	printf("Case %d: %d\n", ++ cas, dp[2 * n - 1][1]);
    }
    
    return 0;
}