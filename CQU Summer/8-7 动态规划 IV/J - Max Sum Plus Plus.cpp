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
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int a[N], dp[N], sum[N], tmp[2][N];

// Imp

void init() {
    mem(dp, 0);
    FOR(i, 0, n) tmp[0][i] = 0;
    FOR(i, 0, n) tmp[1][i] = - inf;
}

void read() {
    FOR(i, 1, n) si(a[i]), sum[i] = sum[i-1] + a[i];
}

// Main Pro
void solve() {
    read(), init();

    int k = 0;
    FOR(i, 1, m) {
    	tmp[1-k][i-1] = - inf;
    	FOR(j, i, n) {
    		if(i == j) dp[j] = sum[j];
    		else dp[j] = max(dp[j-1], tmp[k][j-1]) + a[j];
    		tmp[1-k][j] = max(tmp[1-k][j-1], dp[j]);
    	}
    	k = !k;
    }
    int ans = - inf;
    FOR(i, m, n) Max(ans, dp[i]);
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif


    // si(T); while(T --) solve();
    // while(si(n), n) solve();
    while(sii(m, n) != EOF) solve();
    
  
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}