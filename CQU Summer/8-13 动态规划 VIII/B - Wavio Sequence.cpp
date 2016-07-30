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
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int n, ans, cnt, a[N], lr[N], rl[N];

void LIS(int dp[]) {
    VI v;
    vector<int>:: iterator it;
    int top = 0;
    v.pb(a[0]);
    dp[0] = 1;
    REP(i, 1, n) {
        if(a[i] > v[top]) { v.pb(a[i]); top ++; }
        else {
            it = lower_bound(ALL(v), a[i]);
            *it = a[i];
        }
        dp[i] = top + 1;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(~si(n)) {
        ans = 0;
        rep(i, n) si(a[i]);
        LIS(lr);
        reverse(a, a + n);
        LIS(rl);
        rep(i, n) Max(ans, min(lr[i], rl[n-i-1]) * 2 - 1);
        put(ans);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}