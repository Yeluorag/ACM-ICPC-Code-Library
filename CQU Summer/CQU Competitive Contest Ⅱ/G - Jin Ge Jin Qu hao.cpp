// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, t;
int a[55], dp[N], dp2[N];

// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	int tot = 0;
    	mem(dp, 0), mem(dp2, 0);
    	sii(n, t);
    	FOR(i, 1, n) { si(a[i]); tot += a[i]; }
    	t = min(t - 1, tot);
    	FOR(i, 1, n) {
    		for(int j = t; j >= a[i]; j --) {
    			if(dp[j] < dp[j-a[i]] + 1) {
    				dp[j] = dp[j-a[i]] + 1;
    				dp2[j] = dp2[j-a[i]] + a[i];
    			}
    			else if(dp[j] == dp[j-a[i]] + 1) {
    				Max(dp2[j], dp2[j-a[i]] + a[i]);
    			}
    		}
    	}
    	printf("Case %d: %d %d\n", ++ cas, dp[t] + 1, dp2[t] + 678);
    }
    
    return 0;
}