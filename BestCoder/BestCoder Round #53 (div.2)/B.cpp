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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int g[N][N], f[N];
int par[N], cnt[N];
// Imp


#define LOCAL
int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    while(si(n) != EOF) {
    	mem(par, -1);
    	mem(g, 0);
    	mem(cnt, 0);
    	mem(f, 0x3f);
    	int a, b;
    	rep(i, n - 1) {
    		sii(a, b);
    		g[a][b] = 1;
    		par[b] = a;
    		g[1][b] = g[1][a] + 1;
    		f[b] = g[1][b];
    		cnt[f[b]] ++;
    	}
    	int ans = 1, flag = 0;
    	FOR(i, 2, n) {
    		if(cnt[i] && flag) ans = 0;
    		if(cnt[i] > 1) flag = 1;
    	}
    	printf("%s\n", ans ? "YES" : "NO");
    }
    
    return 0;
}