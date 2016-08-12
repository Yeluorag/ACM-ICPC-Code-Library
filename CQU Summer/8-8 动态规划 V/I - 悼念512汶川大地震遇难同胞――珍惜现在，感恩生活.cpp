#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 4e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, p[N], h[N], c[N], dp[105][N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(T);
    while(T --) {
    	sii(n, m);
    	rep(i, m) { si(p[i]), sii(h[i], c[i]); }
    	mem(dp, 0);
    	rep(i, m) {
    		for(int j = 0; j <= n; j ++) {
    			FOR(k, 0, c[i]) {
    				if(k * p[i] > j) break;
    				dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*p[i]] + k * h[i]);
    			}
    		}
    	}
    	printf("%d\n", dp[m][n]);
    }
    
    return 0;
}