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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][2];
char s[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%s", s + 1);
    	n = strlen(s + 1);
    	mem(dp, 0);
    	dp[0][1] = 1;
    	for(int i = 1; i <= n; i ++) {
    		if(s[i] >= 'A' && s[i] <= 'Z') {
				dp[i][1] = min(dp[i-1][1] + 1, dp[i-1][0] + 2);
				dp[i][0] = min(dp[i-1][1] + 2, dp[i-1][0] + 2);
			} else {
				dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + 2);
				dp[i][1] = dp[i-1][1] + 2;
			}
    	}
    	printf("%d\n", dp[n][0]);
    }
    
    return 0;
}