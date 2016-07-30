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
const int inf = 0x3f3f3f3f, N = 20, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct Point {
	int x, y;
}p[N];
int line[N][N], dp[1 << 17];
bool col(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x);
}
void init() {
	mem(line, 0);
	for(int i = 0; i < n; i ++) {
		for(int j = i + 1; j < n; j ++) {
			for(int k = 0; k < n; k ++) {
				if(col(p[i], p[j], p[k])) line[i][j] += (1 << k);
			}
		}
	}
}
int dfs(int s) {
	if(dp[s] != inf) return dp[s];
	int cnt = __builtin_popcount(s);
	if(cnt == 0) return dp[s] = 0;
	if(cnt <= 2) return dp[s] = 1;
	for(int i = 0; i < n; i ++) if(s & (1 << i)) {
		for(int j = i + 1; j < n; j ++) if(s & (1 << j)) {
			dp[s] = min(dp[s], dfs(s - (s & line[i][j])) + 1);
		}
		break;
	}
	return dp[s];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	for(int i = 0; i < n; i ++) sii(p[i].x, p[i].y);
    	init();
    	mem(dp, 0x3f);
    	printf("Case %d: %d\n", ++ cas, dfs((1 << n) - 1));
    }
    
    return 0;
}