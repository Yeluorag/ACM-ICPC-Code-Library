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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
double x[N], y[N], dp[N][N];

// Imp
inline double Dis(int i, int j) { return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])); }

void init() {
    mem(dp, 0);
    dp[2][1] = Dis(1, 2);
}

void read() {
    FOR(i, 1, n) scanf("%lf%lf", &x[i], &y[i]);
}

// Main Pro
void solve() {
    read(), init();
    FOR(i, 3, n) {
    	dp[i][i-1] = inf;
    	REP(j, 1, i - 1) {
    		Min(dp[i][i-1], dp[i-1][j] + Dis(i, j));
    		dp[i][j] = dp[i-1][j] + Dis(i, i - 1);
    	}
    }
    double ans = inf;
    REP(i, 1, n) Min(ans, dp[n][i] + Dis(n, i));
    printf("%.2lf\n", ans);
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif


    // si(T); while(T --) solve();
    while(si(n) != EOF) solve();
    // while(~sii(n, m), n + m) solve();
    
  
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}