#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, h[N], v[N];
vector<int> ans;
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	ans.clear();
	mem(h, 0);
	mem(v, 0);
    si(n); int num = n * n;
    int x, y;
    rep(i, num) {
    	sii(x, y);
    	if(!h[x] && !v[y]) {
    		h[x] = 1;
    		v[y] = 1;
    		ans.pb(i + 1);
    	}
    }
    sort(ALL(ans));
    int sz = ans.size();
    rep(i, sz - 1) printf("%d ", ans[i]);
    printf("%d\n", ans[sz - 1]);
    return 0;
}