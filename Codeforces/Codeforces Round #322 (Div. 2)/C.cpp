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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k;
int ans;
struct node {
	int v, r;
}a[N];
// Imp

bool cmp(node p, node q) { return p.r < q.r; }
bool cmp1(node p, node q) { return p.v < q.v; }

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	while(sii(n, k) != EOF){
		ans = 0;
	    rep(i, n) { 
	    	si(a[i].v);
	    	a[i].r = 10 - a[i].v % 10;
	    	ans += a[i].v / 10;
	    }
	    sort(a, a + n, cmp);
	    rep(i, n) {
	    	if(k <= 0) break;
	    	if(k >= a[i].r) {
	    		k -= a[i].r;
	    		a[i].v += a[i].r;
	    		ans ++;
	    	}
	    }
	    sort(a, a + n, cmp1);
	    rep(i, n) {
	    	if(k <= 0) break;
	    	int res = 100 - a[i].v;
	    	if(k > res) {
	    		k -= res;
	    		ans += res / 10;
	    	} else {
	    		ans += k / 10;
	    		k = 0;
	    		break;
	    	}
	    }
	    cout << ans << endl;
	}
    return 0;
}