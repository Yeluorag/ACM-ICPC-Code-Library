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
const int inf = 0x3f3f3f3f, N = 10, MOD = 1e9 + 7;

int T, cas = 0;
LL n, m;

// Imp
LL random(LL n) {
	return (LL)((double)rand() / RAND_MAX * n + 0.5);
}

LL multi_mod(LL a, LL b, LL m) {
	LL ret = 0;
	a %= m;
	while(b > 0) {
		if(b & 1) ret = (ret + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return ret;
}

LL quick_mod(LL a, LL b, LL m) {
	LL ret = 1;
	a %= m;
	while(b > 0) {
		if(b & 1) ret = ret * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ret;
}

bool Miller_Rabin(LL n) {
	if(n == 2) return true;
	if(n < 2 || !(n & 1)) return false;
	LL m = n - 1;
	int k = 0;
	while((m & 1) == 0) {
		k ++;
		m >>= 1;
	}
	rep(i, N) {
		LL a = rand() % (n - 1) + 1;
		LL x = quick_mod(a, m, n);
		LL y = 0;
		rep(j, k) {
			y = multi_mod(x, x, n);
			if(y == 1 && x != 1 && x != n - 1) return false;
			x = y;
		}
		if(y != 1) return false;
	}
	return true;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(cin >> n) {
    	printf("%s\n", Miller_Rabin(n) ? "Yes" : "No");
    }
    
    return 0;
}