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
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;

// Imp
bool g[N][N], vis[N];
int link[N];
bool find(int x) {
	rep(y, n) {
		if(g[x][y] && !vis[y]) {
			vis[y] = true;
			if(link[y] == -1 || find(link[y])) {
				link[y] = x;
				return true;
			}
		}
	}
	return false;
}
void init() {
	mem(link, -1);
	mem(g, false);
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    while(si(n) != EOF) {
    	int ans = 0, a, t;
    	init();
    	rep(i, n) {
    		scanf("%d: (%d)", &a, &m);
    		rep(j, m) {
    			si(t);
    			g[a][t] = g[t][a] = 1;
    		}
    	}
    	rep(i, n) {
    		mem(vis, 0);
    		if(!find(i)) ans ++;
    	}
    	put(ans + (n - ans) / 2);
    }
    
    return 0;
}