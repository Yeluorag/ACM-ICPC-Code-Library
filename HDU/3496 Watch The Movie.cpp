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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
const int L = 1e3 + 5;
// Macro end

int T, cas = 0;
int n, m, l, dp[N][L], w[N], v[N];

// Imp
// Use Last Group
void ZeroOne_Pack(int weight, int value, int m) {
	for(int i = m; i >= weight; i --)
		dp[i] = max(dp[i], dp[i-weight] + value);
}
// Use This Group
void Complete_Pack(int weight, int value, int m) {
	for(int i = weight; i <= m; i ++)
		dp[i] = max(dp[i], dp[i-weight] + value);
}
// n: Number of Group, m: Total Weight of Pack
int Multi_Pack(int w[], int v[], int num[], int n, int m) {
	mem(dp, 0);
	for(int i = 1; i <= n; i ++) {
		if(num[i] * w[i] > m)
			Complete_Pack(w[i], v[i], m);
		else {
			for(int k = 1; k < num[i]; k *= 2) {
                ZeroOne_Pack(k * w[i], k * v[i], m, dp);
                num[i] -= k;
            }
			ZeroOne_Pack(num[i] * w[i], num[i] * v[i], m);
		}
	}
	return dp[m];
}
// m: Number of Limited count, l: Total Weight of Pack
int TwoDimension_ZeroOne_Pack(int w[], int v[], int n, int m, int l) {
	mem(dp[0], 0);
	for(int i = 1; i <= n; i ++) for(int j = 0; j <= l; j ++) dp[i][j] = - inf;
	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= 1; j --) {
			for(int k = l; k >= w[i]; k --) {
				dp[j][k] = max(dp[j][k], dp[j-1][k-w[i]] + v[i]);
			}
		}
	}
	return dp[m][l];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	siii(n, m, l);
    	FOR(i, 1, n) sii(w[i], v[i]);
    	int ans = TwoDimension_ZeroOne_Pack(w, v, n, m, l);
    	if(ans < 0) ans = 0;
    	put(ans);
    }
    
    return 0;
}