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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a, b, k, ans;
int dp[20][N][N], num[21];
int Gao(int x) {
	int cnt = 0;
	mem(dp, 0);
	// while(x > 0) {
	// 	num[cnt ++] = x % 10;
	// 	x /= 10;
	// }
	for(int i = 10; i >= 0; i --) num[i] = x % 10, x /= 10;
	int sa = 0, sn = 0;
	// for(int i = cnt - 1; i > 0; i --) {
	rep(i, 10) {
		sa = (sa * 10 + num[i]) % k, sn = (sn + num[i]) % k;
		rep(j, k) rep(l, k) rep(d, 10)
			dp[i + 1][(j + d) % k][(l * 10 + d) % k] += dp[i][j][l];
		rep(j, num[i + 1]) dp[i + 1][(sn + j) % k][(sa * 10 + j) % k] ++;
	}
	return dp[20][0][0] + ((sn + num[20]) % k == 0 && (sa * 10 + num[20]) % k == 0);
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	siii(a, b, k);
    	if(k > 90) puts("0");
    	else printf("%d\n", Gao(b) - Gao(a - 1));
    }
    
    return 0;
}