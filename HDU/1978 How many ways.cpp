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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e4;
// Macro end

int T, cas = 0;
int n, m, a[N][N], dp[N][N];
// Imp
int dfs(int x, int y) {
	int& ret = dp[x][y];
	if(ret >= 0) return ret;
	ret = 0;
	if(x == n - 1 && y == m - 1) return ret = 1;
	FOR(i, 0, a[x][y]) {
		FOR(j, 0, a[x][y] - i){
			if(i + j == 0) continue;
			int nx = x + i, ny = y + j;
			if(nx >= n || ny >=m) continue;
			ret = (ret + dfs(nx, ny)) % MOD;
		}
	}
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	mem(dp, -1);
    	sii(n, m);
    	rep(i, n) rep(j, m) si(a[i][j]);
    	printf("%d\n", dfs(0, 0));
    }
 
    return 0;
}