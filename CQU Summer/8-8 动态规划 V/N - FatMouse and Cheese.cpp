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
int n, k;
int a[N][N], dp[N][N], vis[N][N];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

// Imp

void init() {
    mem(dp, 0);
}

void read() {
    rep(i, n) rep(j, n) si(a[i][j]);
}

int dfs(int x, int y) {
    int& ret = dp[x][y];
    if(dp[x][y] > 0) return ret;
    rep(i, 4) {
        FOR(j, 1, k){
            int nx = x + dx[i] * j, ny = y + dy[i] * j;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(a[nx][ny] > a[x][y])
                Max(ret, dfs(nx, ny));
        }
    }
    return ret = ret + a[x][y];
}

// Main Pro
void solve() {
    read(), init();
    put(dfs(0, 0));
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    
    // si(T); while(T --) solve();
    // while(si(n), n) solve();
    while(sii(n, k), n + k + 2) solve();
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}