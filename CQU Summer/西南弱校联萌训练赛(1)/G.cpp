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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 3e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
struct SparseTable{
	static const int MaxLength = N;
	int f[MaxLength][20];
	int (*cp) (int, int);

	void build(int *a, int n, int (*func) (int, int)) {
		for(int i = 0; i <= n - 1; i ++) f[i][0] = a[i];
		cp = func;
		for(int k = 1; (1 << k) <= n; k ++)
			for(int i = 0; i + (1 << k) <= n; i ++) {
				int len = 1 << (k - 1);
				f[i][k] = func (f[i][k-1], f[i+len][k-1]);
			}
	}

	int query(int L, int R) {
		int len = R - L + 1, k = 0;
		while((1 << k) < len) k ++;
		if(k) k --; len = (1 << k);
		return cp(f[L][k], f[R-len+1][k]);
	}
};
inline int MIN(int x, int y) {
	return x < y ? x : y;
}

int GCD(int x, int y) {
	return y == 0? x : GCD(y, x % y);
}
SparseTable minST, gcdST;
int a[N];

// Imp
bool check(int L) {
	for(int i = 0; i + L <= n; i ++) {
		int j = i + L - 1;
		if(minST.query(i, j) == gcdST.query(i, j)) return true;
	}
	return false;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	rep(i, n) si(a[i]);
    	minST.build(a, n, MIN);
    	gcdST.build(a, n, GCD);
    	int l = 1, r = n + 1, mid;
    	while(l < r) {
    		mid = (l + r) >> 1;
    		if(check(mid)) l = mid + 1;
    		else r = mid;
    	}
    	int len = l - 1;
    	VI tmp;
    	for(int i = 0; i + len <= n; i ++) {
    		int j = i + len - 1;
    		if(minST.query(i, j) == gcdST.query(i, j)) tmp.pb(i);
    	}
    	int sz = tmp.size();
    	printf("%d %d\n",sz, len - 1);
    	rep(i, sz - 1) printf("%d ", tmp[i] + 1);
    	put(tmp[sz-1] + 1);
    }
    
    return 0;
}
/*
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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 3e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, mx, a[N], vis[N], b[N];
VI ans;

// Imp


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(n);
    rep(i, n) si(a[i]);
    rep(i, n) {
        if(vis[i]) continue;
        int l = i, r = i, x = a[i];
        while(l) {
            vis[l] = 1;
            if(a[l-1] % x) break;
            l --;
        }
        while(r < n - 1) {
            vis[r] = 1;
            if(a[r+1] % x) break;
            r ++;
        }
        if(r - l > mx) {
            mx = r - l;
            ans.clear();
            mem(b, 0);
            ans.pb(l + 1);
            b[l] = 1;
        }
        if(r - l == mx && !b[l]) {
            ans.pb(l + 1);
            b[l] = 1;
        }
    }
    printf("%d %d\n", ans.size(), mx);
    int sz = ans.size();
    rep(i, sz - 1) printf("%d ", ans[i]);
    put(ans[sz-1]);
    
    return 0;
}
*/