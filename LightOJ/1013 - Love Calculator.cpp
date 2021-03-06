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
const int inf = 0x3f3f3f3f, N = 30 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N];
LL cnt[N][N];
char s1[N], s2[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	mem(dp, 0), mem(cnt, 0);
    	scanf("%s", s1 + 1);
    	scanf("%s", s2 + 1);
    	n = strlen(s1 + 1), m = strlen(s2 + 1);
    	for(int i = 1; i <= n; i ++) {
    		for(int j = 1; j <= m; j ++) {
    			if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
    			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    	for(int i = 0; i <= m; i ++) cnt[0][i] = 1;
    	for(int i = 0; i <= n; i ++) cnt[i][0] = 1;

    	for(int i = 1; i <= n; i ++) {
    		for(int j = 1; j <= m; j ++) {
    			if(s1[i] == s2[j]) cnt[i][j] = cnt[i-1][j-1];
    			else {
    				if(dp[i][j] == dp[i-1][j]) cnt[i][j] += cnt[i-1][j];
    				if(dp[i][j] == dp[i][j-1]) cnt[i][j] += cnt[i][j-1];
    			}
    		}
    	}
    	printf("Case %d: %d %lld\n", ++ cas, n + m - dp[n][m], cnt[n][m]);
    }
    
    return 0;
}