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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ans, maz[N][N], dp[N][N];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string s;

int dfs(int x, int y) {
	if(dp[x][y] > 0) return dp[x][y];
	dp[x][y] = 1;
	rep(i, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if(maz[nx][ny] < maz[x][y]) dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	return dp[x][y];
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(T);
    while(T --) {
    	cin >> s;
    	sii(n, m);
    	rep(i, n) rep(j, m) si(maz[i][j]);
    	mem(dp, -1);
    	ans = -1;
    	rep(i, n) rep(j, m) ans = max(ans, dfs(i, j));
    	cout << s << ": " << ans << endl;
    }
    
    return 0;
}