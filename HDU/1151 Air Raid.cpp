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
const int inf = 0x3f3f3f3f, N = 1e2 + 50, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
bool g[N][N], used[N];
int link[N];
// Imp
bool find(int u) {
	FOR(v, 1, n) {
		if(g[u][v] && !used[v]) {
			used[v] = true;
			if(link[v] == -1 || find(link[v])) {
				link[v] = u;
				return true;
			}
		}
	}
	return false;
}

void work() {
	int ans = 0;
	FOR(i, 1, n) {
		mem(used, 0);
		if(!find(i)) ans ++;
	}
	put(ans);
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
		mem(g, false);
		mem(link, -1);
    	int u, v;
    	rep(i, m) sii(u, v), g[u][v] = 1;
    	work();
    }
    
    return 0;
}