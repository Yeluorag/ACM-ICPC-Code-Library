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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e4 + 7;

int T, cas = 0;
int n, m;
int a[N], b[N], sum[N], fsum[N];
int f(int x) { return (1890 * x + 143) % MOD; }
int s(int l, int r) { return sum[r] - sum[l-1]; }
int fs(int l, int r) { return fsum[r] - fsum[l-1]; }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	sum[0] = 0, fsum[0] = 0;
    	for(int i = 1; i <= n; i ++) { 
    		si(a[i]);
    		b[i] = f(a[i]);
    		sum[i] = sum[i-1] + a[i];
    		fsum[i] = fsum[i-1] + b[i];
    	}
    	// printf("Case %d:\n", ++ cas);
    	// for(int i = 1; i <= n; i ++) printf("%d ", a[i]); puts("");
    	// for(int i = 1; i <= n; i ++) printf("%d ", b[i]); puts("");

    	int l = 0, r = 1, ul = -1, ur = -1, tmp = 0;

    	for(int i = 1; i <= n; i ++) {
    		if(s(l, i) > fs(l, i)) {
    			l = r = i + 1;
    		} else {
    			r = i;
    			if(fs(l, r) - s(l, r) > tmp) {
    				tmp = fs(l, r) - s(l, r);
    				ul = l, ur = r;
    			}
    		}
    	}
    	// printf("l: %d, r: %d\n", ul, ur);
    	int ans = 0;
    	if(ul > n || ul == -1) ans = sum[n];
    	else ans = s(1, ul - 1) + fs(ul, ur) + s(ur + 1, n);
    	printf("%d\n", ans);
    }
    
    return 0;
}