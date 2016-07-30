// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, M = 125, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, a[N];
double mp[150][150];
double dp[10005][150];
int num[10005];

int main() {
#ifdef LOCAL
	IN // OUT
#endif
	int m, n;
	while(scanf("%d", &m) != EOF) {
		m = m * (m - 1) * (m - 2) / 6;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%lf", &mp[i][j]);
			}
		}
		scanf("%d", &n);
		mem(dp, 0);
		for(int i = 0; i < m; i++) dp[0][i] = 1;
		for(int i = 1; i <= n; i++) {
			scanf("%d", num + i);
			for(int j = 0; j < m; j++) {
				double tmp = dp[i-1][j] * mp[j][num[i]];
				Max(dp[i][j], tmp);
				Max(dp[i][num[i]], tmp);
			}
		}
		double ans = 0;
		for(int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
		printf("%.6f\n", ans);
	}
	return 0;
}