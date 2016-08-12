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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ans = 0;
int vis[N], a[N], b[N], hs[10 * N];

// Imp


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(n);
    rep(i, n) si(a[i]), b[i] = a[i], hs[a[i]] = i;
    sort(b, b + n);	
    rep(i, n) {
    	if(!vis[i]) {
    		int id = i, sum = 0, mi = inf, len = 0;
    		do {
    			vis[id] = 1;
    			sum += a[id];
    			mi = min(mi, a[id]);
    			len ++;
    			id = hs[b[id]];
    		} while(id != i);
    		ans += min(sum + (len - 2) * mi, sum + mi + (len + 1) * b[0]);
    	}
    }
    printf("%d\n", ans);
    return 0;
}