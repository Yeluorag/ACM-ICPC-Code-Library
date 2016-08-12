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
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
const int inf = 0x3f3f3f3f, N = 2e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, x, y, a, b;
int dp[N];

// Imp

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(scanf("%d%d%d%d%d", &n, &x, &y, &a, &b) != EOF) {
        mem(dp, 0);
        if(a > b) swap(a, b);
        dp[0] = 1;
        FOR(i, 0, n) {
            if(i < a) {
                if(i + x <= a) dp[i+x] = (dp[i+x] + dp[i]) % MOD;
                if(i + y <= a) dp[i+y] = (dp[i+y] + dp[i]) % MOD;
            } else if(i >= a && i < b) {
                if(i + x <= b) dp[i+x] = (dp[i+x] + dp[i]) % MOD;
                if(i + y <= b) dp[i+y] = (dp[i+y] + dp[i]) % MOD;
            } else {
                dp[i+x] = (dp[i+x] + dp[i]) % MOD;
                dp[i+y] = (dp[i+y] + dp[i]) % MOD;
            }
        }
        put(dp[n]);
    }
    
    return 0;
}