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
const int inf = 0x3f3f3f3f, N = 2e1 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int dp[N][205];
// Imp
void init() {
    mem(dp, 0);
    rep(i, N) dp[n][0] = 1;
    rep(i, N) FOR(j, 0, i) FOR(k, 0, 190)
    if(dp[i-j][k]) dp[i][(i - j) * j + k] = 1;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    while(si(n) != EOF) {
        printf("0");
        FOR(i, 1, 190) if(dp[n][i]) printf(" %d", i);
        puts("");
    }
    
    
    
    return 0;
}