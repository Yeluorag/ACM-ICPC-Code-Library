// Header.
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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
LL n, m, p;
// Imp
LL quick_mod(LL a, LL b) {
	LL ret = 1;
	a %= p;
	while(b) {
		if(b & 1) ret = ret * a % p, b --;
		b >>= 1;
		a = a * a % p;
	}
	return ret;
}

LL C(LL n, LL m) {
	if(m > n) return 0;
	LL a, b, ret = 1;
	for(LL i = 1; i <= m; i ++) {
		a = (n + i - m) % p;
		b = i % p;
		ret = ret * (a * quick_mod(b, p - 2) % p) % p;
	}
	return ret;
}

LL Lucas(LL n, LL m) {
	if(m == 0) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(cin >> n >> m >> p) cout << Lucas(n - m + 1, m) << endl;
    
    return 0;
}