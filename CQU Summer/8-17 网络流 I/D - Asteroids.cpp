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
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;

// Imp
int ans = 0;
int v1, v2;
bool grid[N][N], vis[N];
int link[N];
bool find(int x) {
	FOR(y, 1, v2) {
		if(grid[x][y] && !vis[y]) {
			vis[y] = 1;
			if(link[y] == 0 || find(link[y])) {
				link[y] = x;
				return true;
			}
		}
	}
	return false;
}

void search() {
	FOR(i, 1, v1) {
		mem(vis, 0);
		if(find(i)) ans ++; 
	}
}

void read() {
    int x, y;
    FOR(i, 1, m) sii(x, y) , grid[x][y] = 1;
}

void init() {
    ans = 0;
    mem(grid, 0);
}

// Main Pro
void solve() {
    init(), read();
    search();
    put(ans);
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif


    // si(T); while(T --) solve();
    // while(~si(n), n) solve();
    while(sii(n, m) != EOF) solve();
    
  
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}