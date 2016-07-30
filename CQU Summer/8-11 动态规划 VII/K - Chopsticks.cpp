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
#define ss(a) scanf("%s", a)
#define put(a) printf("%d\n", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e3 + 10, MOD = 1e9 + 7;

int T, cas = 0;
int n, k, a[N * 5], dp[N][N * 5];
bool cmp(int a, int b) { return a > b; }
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        sii(k, n); mem(dp, 0x3f); k += 8;
        rep(i, n) si(a[i]), dp[0][i] = 0;
        sort(a, a + n, cmp);
        FOR(i, 1, k) FOR(j, i * 3 - 1, n)
        dp[i][j] = min(dp[i][j-1], dp[i-1][j-2] + (a[j] - a[j-1]) * (a[j] - a[j-1]));
        put(dp[k][n-1]);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}