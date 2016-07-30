#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
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
const int inf = 0x3f3f3f3f, N = 2e1 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, r, vis[N];
double p[N], ans[N], tot;

void Mem() { mem(ans, 0), mem(vis, 0); }

void dfs(int cur, int cnt) {
	if(cnt == r) {
		double tmp = 1.0;
		FOR(i, 1, n) {
			if(vis[i]) tmp *= p[i];
			else tmp *= (1 - p[i]);
		}
		tot += tmp;
		FOR(i, 1, n) if(vis[i]) ans[i] += tmp;
		return;
	}
	FOR(i, cur + 1, n) {
		vis[i] = 1;
		dfs(i, cnt + 1);
		vis[i] = 0;
	}
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(~sii(n, r) && (n + r)) {
    	Mem(); tot = 0;
    	FOR(i, 1, n) scanf("%lf", &p[i]);
    	dfs(0, 0);
    	printf("Case %d:\n", ++ cas);
    	FOR(i, 1, n) printf("%.6lf\n", ans[i] / tot);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}