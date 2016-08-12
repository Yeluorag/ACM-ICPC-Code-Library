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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 9;

int T, cas = 0;
LL n, m, k;
LL fac[N], A[N], B[N], inv[N];
// Imp
void init() {
	fac[0] = A[0] = B[0] = inv[0] = 1;
	REP(i, 1, N) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		A[i] = A[i - 1] * 691504013 % MOD;
		B[i] = B[i - 1] * 308495997 % MOD;
	}
}

LL quick_mod(LL a, LL b, LL MOD) {
	LL ans = 1;
	a %= MOD;
	while(b > 0) {
		if(b & 1) {
			ans = ans * a % MOD;
			b --;
		}
		b >>= 1;
		a = a * a % MOD;
	}
	return ans;
}

LL Work(LL n, LL k) {
	LL ans = 0;
	FOR(r, 0, k) {
		LL t = A[k - r] * B[r] % MOD;
		LL x = fac[k];
		LL y = fac[k - r] * fac[r] % MOD;
		LL c = x * quick_mod(y, MOD - 2, MOD) % MOD;
		LL tmp = t * (quick_mod(t, n, MOD) - 1) % MOD * quick_mod(t - 1, MOD - 2, MOD) % MOD;
		if(t == 1) tmp = n % MOD;
		tmp = tmp * c % MOD;
		if(r & 1) ans -= tmp;
		else ans += tmp;
		ans %= MOD;
	}
	LL m = quick_mod(383008016, MOD - 2, MOD);
	ans = a5ns * quick_mod(m, k, MOD) % MOD;
	ans = (ans % MOD + MOD) % MOD;
	return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	init();
	si(T);
	while(T --) {
		cin >> n >> k;
		cout << Work(n, k) << endl;
	}
    
    
    return 0;
}