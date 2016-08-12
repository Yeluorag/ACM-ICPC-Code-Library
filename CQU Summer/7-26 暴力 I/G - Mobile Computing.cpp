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
const int inf = 0x3f3f3f3f, N = (1 << 7), MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int vis[N];
double w[7], sumw[N], r;
struct Node{
	double l, r;
	Node() {}
	Node(double ll, double rr) {
		l = ll;
		r = rr;
	}
};
vector<Node> node[N];

// Imp
void dfs(int s) {
	if(vis[s]) return;
	vis[s] = 1;
	if(__builtin_popcount(s) == 1) {
		node[s].pb(Node(0, 0));
		return;
	}
	for(int l = (s - 1) & s; l > 0; l = (l - 1) & s) {
		int r = s ^ l;
		dfs(l); dfs(r);
		rep(i, node[l].size()) {
			rep(j, node[r].size()) {
				double ll = min(-sumw[r] / (sumw[l] + sumw[r]) + node[l][i].l, sumw[l] / (sumw[l] + sumw[r]) + node[r][j].l);
				double rr = max(sumw[l] / (sumw[l] + sumw[r]) + node[r][j].r, -sumw[r] / (sumw[l] + sumw[r]) + node[l][i].r);
				node[s].pb(Node(ll, rr));
			}
		}
	}
}


void solve() {
	double ans = -1;
	int s = (1 << n) - 1;
	dfs(s);
	rep(i, node[s].size()) {
		if(node[s][i].r - node[s][i].l < r) {
			Max(ans, node[s][i].r - node[s][i].l);
		}
	}
	if(ans == -1) puts("-1");
	else printf("%.16lf\n", ans);
}


//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
  	si(T);
  	while(T --) {
  		mem(vis, 0);
  		mem(node, 0);
  		scanf("%lf%d", &r, &n);
  		rep(i, n) scanf("%lf", &w[i]);
  		REP(i, 0, (1 << n)) {
  			sumw[i] = 0;
  			rep(j, n) {
  				if(i & (1 << j))
  					sumw[i] += w[j];
  			}
  		}
  		solve();
  	}

    return 0;
}