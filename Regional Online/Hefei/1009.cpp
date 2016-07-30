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
const int inf = 0x3f3f3f3f, N = 30 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, num;
int a[N][N], ans;
struct node {
	int fac, sum, c[2005];
}dp[N][N];
// Imp
int fac(int x) { return x * x; }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        sii(n, m);
        num = n + m - 1;
        FOR(i, 1, n) FOR(j, 1, m) si(a[i][j]);
        mem(dp, 0);

        ans = inf;

        FOR(j, 1, m) {
        	dp[1][j].fac = dp[1][j - 1].fac + fac(a[1][j]);
        	dp[1][j].sum = dp[1][j - 1].sum + a[1][j];
        	dp[1][j].c[dp[1][j].sum] = dp[1][j].fac;
        }
        FOR(i, 2, n) {
        	dp[i][1].fac = dp[i - 1][1].fac + fac(a[i][1]);
        	dp[i][1].sum = dp[i - 1][1].sum + a[i][1];
        	dp[i][1].c[dp[i][1].sum] = dp[i][1].fac;
        }
        FOR(i, 2, n) {
        	FOR(j, 2, m) {
        		rep(k, 2005) {
        			int tmp = k + a[i][j];
        			if(dp[i][j - 1].c[k]) {
        				if(dp[i][j].c[tmp]) dp[i][j].c[tmp] = min(dp[i][j].c[tmp], dp[i][j - 1].c[k] + fac(a[i][j]));
        				else dp[i][j].c[tmp] = dp[i][j - 1].c[k] + fac(a[i][j]);
        			}
        			if(dp[i - 1][j].c[k]) {
        				if(dp[i][j].c[tmp]) dp[i][j].c[tmp] = min(dp[i][j].c[tmp], dp[i - 1][j].c[k] + fac(a[i][j]));
        				else dp[i][j].c[tmp] = dp[i - 1][j].c[k] + fac(a[i][j]);
        			}
        		}
        	}
        }
        rep(k, 2005) if(dp[n][m].c[k]) ans = min(ans, num * dp[n][m].c[k] - k * k);
        printf("Case #%d: %d\n", ++ cas, ans);
        
    }
    
    return 0;
}