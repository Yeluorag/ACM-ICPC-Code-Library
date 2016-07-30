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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
LL a[N], l[N], r[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n), n) {
    	LL ans = 0;
  		l[0] = 0;
  		r[n-1] = n - 1;
    	for(int i = 0; i < n; i ++) scanf("%lld", &a[i]);
    	for(int i = 0; i < n; i ++) {
    		int j = i;
    		while(j && a[i] <= a[j-1]) j = l[j-1];
    		l[i] = j;
    	}
    	for(int i = n - 2; i >= 0; i --) {
    		int j = i;
    		while(j < n - 1 && a[i] <= a[j+1]) j = r[j+1];
    		r[i] = j;
    	}
    	for(int i = 0; i < n; i ++) ans = max(ans, a[i] * (r[i] - l[i] + 1));
    	printf("%lld\n", ans);
    }
    
    return 0;
}