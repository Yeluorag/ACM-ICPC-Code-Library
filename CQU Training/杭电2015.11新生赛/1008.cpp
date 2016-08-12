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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ans;
LL x[N], k, frd;
int p[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%d%d%lld", &n, &m, &k);
    	frd = ans = 0;
    	for(int i = 1; i <= n; i ++) scanf("%lld", &x[i]);
    	for(int i = 1; i <= m; i ++) {
    		si(p[i]);
    		frd += x[p[i]];
    		x[p[i]] = 0;
    	}
    	if(frd > k) {
    		puts("-1");
    		continue;
    	}
    	k -= frd;
    	sort(x + 1, x + n + 1);
    	for(int i = 1; i <= n; i ++) {
    		k -= x[i];
    		if(k >= 0) ans ++;
    		else break;
    	}
    	printf("%d\n", ans);
    }
    
    return 0;
}