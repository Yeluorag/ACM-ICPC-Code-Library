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
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N], ans[N];
char s1[N], s2[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	while(scanf("%s%s", s1, s2) != EOF) {
		int len = strlen(s1);
		mem(dp, 0);
		rep(j, len) {
			for(int i = j; i >= 0; i --) {
				dp[i][j] = dp[i + 1][j] + 1;
				FOR(k, i + 1, j) if(s2[i] == s2[k]) Min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
			}
		}
		rep(i, len) ans[i] = dp[0][i];
		rep(i, len) {
			if(s1[i] == s2[i]) ans[i] = ans[i - 1];
			else FOR(j, 0, i) Min(ans[i], ans[j] + dp[j + 1][i]);
		}
		printf("%d\n", ans[len - 1]);
	}
    
    return 0;
}