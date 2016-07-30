// Header.
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
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N], dp[N], cnt[1005], ans = 0;
// Imp
bool cmp(int p, int q) { return p > q; }
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	mem(dp, -1);
	mem(cnt, 0);
	dp[0] = 0;
    sii(n, m);
    rep(i, n) {
    	si(a[i]);
    	cnt[a[i]%m] ++;
    	if(a[i] % m == 0) ans = 1;
    }
    rep(i, m) {
    	FOR(j, 0, m) {
    		if(dp[j] >= 0) {
    			dp[j] = cnt[i];
    		} else if(j < i || dp[j - i] <= 0) { 
    			dp[j] = -1; 
    		} else {
    			dp[j] = dp[j - i] - 1;
    		}
    	}
    }
    if(dp[m] >=0 || dp[0] > 0) ans = 1;
    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}