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
#define lowbit(x) (x&(-x))
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N], b[N], c[N], bit[N];
int sum(int x) {
	int ret = 0;
	while(x > 0) {
		ret += bit[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int i, int x) {
	while(i < N) {
		bit[i] += x;
		i += lowbit(i);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(T);
    while(T --) {
    	si(n);
    	LL ans = 0;
    	for(int i = 1; i <= n; i ++) si(a[i]);
    	mem(bit, 0);
    	for(int i = 1; i <= n; i ++) {
    		b[i] = sum(a[i] - 1);
    		add(a[i], 1);
    	} 
    	mem(bit, 0);
    	for(int i = n; i >= 1; i --) {
    		c[i] = sum(a[i] - 1);
    		add(a[i], 1);
    	}
    	for(int i = 1; i <= n; i ++) ans += (LL)b[i] * (n - i - c[i]) + (LL)(i - 1 - b[i]) * c[i];
    	printf("%lld\n", ans);
    }
	
    return 0;
}