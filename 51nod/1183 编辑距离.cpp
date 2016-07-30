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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N];
char s[N], t[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%s%s", s, t) != EOF) {
    	int n = strlen(s), m = strlen(t);
    	for(int i = 0; i <= n; i ++) dp[i][0] = i;
    	for(int i = 0; i <= m; i ++) dp[0][i] = i;
    	for(int i = 1; i <= n; i ++) {
    		for(int j = 1; j <=m; j ++) {
    			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
    			dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s[i-1] != t[j-1]));
    		}
    	}
    	printf("%d\n", dp[n][m]);
    } 
    
    return 0;
}