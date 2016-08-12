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
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N], cost[30];
char s[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	while(sii(n, m) != EOF) {
		scanf("%s", s);
		char in[2];
		int x, y;
		for(int i = 0; i < n; i ++) {
			scanf("%s%d%d", in, &x, &y);
			cost[in[0] - 'a'] = min(x, y);
		}

		mem(dp, 0);
		for(int j = 1; j < m; j ++) {
			for(int i = j - 1; i >= 0; i --) {
				dp[i][j] = min(dp[i+1][j] + cost[s[i] - 'a'], dp[i][j-1] + cost[s[j] - 'a']);
				if(s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
			}
		}
		printf("%d\n", dp[0][m-1]);
	}    
    
    return 0;
}