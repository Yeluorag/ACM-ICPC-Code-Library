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
const int inf = 0x3f3f3f3f, N = 30 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, k, ans;
int c[N], maz[6][6];

bool check(int nx, int ny) {
	if(nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
	return true;
}
void dfs(int pos) {
	int x = pos / m, y = pos % m;
	if(pos == 25) {
		if(!ans) printf("YES\n");
		ans ++;
		rep(i, n) {
			rep(j, m - 1) printf("%d ", maz[i][j]);
			printf("%d\n", maz[i][m - 1]);
		}
		return;
	}
	FOR(i, 1, k) {
		if(n * m - pos < c[i] * 2) continue;
		int ok = 1;
		if(check(x - 1, y)) if(maz[x - 1][y] == i) ok = 0;
		if(check(x, y - 1)) if(maz[x][y - 1] == i) ok = 0;
		if(ok) {
			c[i] --;
			dfs(pos + 1);
			c[i] ++;
		}
	}
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	ans = 0;
    	siii(n, m, k);
    	mem(maz, -1);
    	FOR(i, 1, k) si(c[i]);
    	printf("Case #%d:\n", ++ cas);
    	dfs(0);
    	if(!ans) printf("NO\n");
    }
    
    return 0;
}