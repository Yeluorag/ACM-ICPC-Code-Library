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
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, dp[N][N];
char s[N], u[N];
// Imp

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
	mem(dp, 0);
	ss(s);
	ss(u);
	n = strlen(s), m = strlen(u);
	rep(i, n) {
		rep(j, m) {
			if(s[i] == u[j]) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = dp[i][j];
		}
	}
	int ans = 0;
	FOR(i, 0, n) FOR(j, 0, m) Max(ans, dp[i][j]);
	put(m - ans);
    
    
    return 0;
}