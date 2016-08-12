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
 
typedef unsigned long long ull;
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
const int inf = 0x3f3f3f3f, N = 30 + 1, MOD = 1e9 + 7;
 
int T, cas = 0;
int n, m;
ull dp[N][905];

void init() {
	FOR(i, 0, 30) dp[i][0] = 1;
	FOR(i, 1, 30) FOR(j, 1, i) {
		dp[i][j] = dp[i-1][j] + dp[i-1][j-1] * (2 * (i - j) + 1);
		if(j >= 2) dp[i][j] += dp[i-1][j-2] * (i - j + 1) * (i - j + 1);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
   
    init();
    si(T);
    while(T --) {
        sii(n, m);
        printf("Case %d: %llu\n", ++ cas, dp[n][m]);
    }
   
    return 0;
}