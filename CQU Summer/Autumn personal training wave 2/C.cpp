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
int n, m, q, x;
int qus[N], ans[N];
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	siii(n, m, q);
    	printf("Case #%d:\n", ++ cas);
    	if(m < n) swap(n, m);
    	rep(i, q) { 
    		si(x);
    		if(x > n + m || x < 2) ans[i] = 0;
    		else {
    			int l, r;
    			if(x - 1 > m) {
    				l = x - m;
    				r = n;
    			} else if(x <= n + 1) {
    				l = 1;
    				r = x - 1;
    			} else {
    				l = 1;
    				r = n;
    			}
    			ans[i] = r - l + 1;  
    		} 
    	}
    	rep(i, q) printf("%d\n", ans[i]);
    }
    
    return 0;
}