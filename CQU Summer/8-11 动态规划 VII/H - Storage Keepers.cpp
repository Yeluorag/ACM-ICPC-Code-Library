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
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define ss(a) scanf("%s", a)
#define put(a) printf("%d\n", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int n, m, p[N];
int dp[N], ans;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(n, m) && n && m) {
        mem(dp, 0); dp[0] = inf;
        FOR(i, 1, m) si(p[i]);
        
        FOR(i, 1, m) for(int j = n; j >= 0; j --) FOR(k, 1, j)
        Max(dp[j], min(dp[j-k], p[i] / k));
        ans = dp[n];
        
        if(!ans) { printf("0 0\n"); continue; }
        else {
            mem(dp, 0x3f); dp[0] = 0;
            FOR(i, 1, m) for(int j = n; j >= 0; j --) for(int k = min(j, p[i] / ans); k > 0; k --)
            Min(dp[j], dp[j-k] + p[i]);
            printf("%d %d\n", ans, dp[n]);
        }
        
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}