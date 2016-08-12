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
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", awe)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
struct edge{
	int u, v, w;
	bool operator < (const edge& rhs) const {
		return w < rhs.w;
	}
}e[N * N];

int p[N], n, m, mxt;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

bool MST(int x) {
	mxt = -1;
	int cnt = 0;
	FOR(i, 0, n) p[i] = i;
	REP(i, x, m) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int x = find(u), y = find(v);
		if(x != y) {
			p[x] = y;
			Max(mxt, w);
			if(++ cnt == n - 1) return true;
		}
	}
	return false;
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(~sii(n, m), n + m) {
    	rep(i, m) siii(e[i].u, e[i].v, e[i].w);
    	sort(e, e + m);
    	int ans = inf;
    	rep(i, m) if(MST(i)) Min(ans, mxt - e[i].w);	//Enum (Max edge - Min edge) in the MST
    	if(ans == inf) ans = -1;
    	put(ans);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}