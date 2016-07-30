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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N];
char s1[N], s2[N];
// Imp


#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	si(T);
	while(T --) {
		scanf("%s", s1);
		scanf("%s", s2);
		n = strlen(s1), m = strlen(s2);
		mem(dp, 0);
		FOR(i, 0, m) dp[0][i] = i;
		FOR(i, 1, n) {
			FOR(j, 1, m) {
				if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = dp[i - 1][j - 1] + 1;
				dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]));
			}
		}
		printf("%d\n", dp[n][m]);
	}
    
    
    return 0;
}