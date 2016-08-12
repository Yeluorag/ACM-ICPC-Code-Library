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
int dp[N], isp[N][N];
char s[N];
int min(int a, int b, int c) { return min(a, min(b, c)); }
void init() {
	mem(isp, 0);
	for(int i = 1; i <= n; i ++) {
		isp[i][i] = 1;
		for(int j = i - 1, k = i + 1; j >= 1 && k <= n && s[j] == s[k]; j --, k ++)
			isp[j][k] = 1;

		for(int j = i, k = i + 1; j >= 1 && k <= n && s[j] == s[k]; j --, k ++) 
			isp[j][k] = 1;
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%s", s + 1);
    	n = strlen(s + 1);
    	init();
    	mem(dp, 0x3f);
    	dp[0] = 0;
    	for(int j = 1; j <= n; j ++) {
    		for(int i = 1; i <= j; i ++) {
    			if(isp[i][j]) dp[j] = min(dp[j], dp[i-1] + 1);
    		}
    	}
    	printf("Case %d: %d\n", ++ cas, dp[n]);
    }
    
    return 0;
}