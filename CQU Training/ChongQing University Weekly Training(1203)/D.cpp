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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
LL n, m;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%lld%lld", &n, &m), n + m) {
    	LL tmp = n * m - 1;
    	if(n == 1) {
    		if(m != 1) printf("%lld %lld Impossible\n", n, m);
    		else printf("%lld %lld Multiple\n", n, m);
    		continue;
    	}
    	if(tmp % (n - 1) == 0) printf("%lld %lld %lld\n", n, m, tmp / (n - 1));
    	else printf("%lld %lld Impossible\n", n, m);
    }
    
    return 0;
}