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
int n, m, k;
double p[N], f[N];

double quick_pow(double a, int b) {
	double ret = 1.0;
	while(b) {
		if(b & 1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	siii(n, k, m);
    	for(int i = 0; i < n; i ++) scanf("%lf", &p[i]);
    	f[0] = 0.0, f[1] = p[0];
    	for(int i = 2; i <= m; i ++) {
    		f[i] = 0.0;
    		for(int j = 0; j < n; j ++) f[i] += p[j] * quick_pow(f[i-1], j);
    	}
    	printf("Case #%d: %.7f\n", ++ cas, quick_pow(f[m], k));
    }
    
    return 0;
}