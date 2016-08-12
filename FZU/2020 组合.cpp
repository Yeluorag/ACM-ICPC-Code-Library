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
int n, m, p;

// Imp
LL Quick_mod(LL a, LL b) {
	 LL ret = 1;
	 a %= p;
	 while(b) {
	 	if(b & 1) ret = ret * a % p, b --;
	 	b >>= 1;
	 	a = a * a % p;
	 }
	 return ret;
}
// Cm(n, m) = n! / (n - m)! * (b!)^(p-2)
LL C(LL n, LL m) {
	if(m > n) return 0;
	LL ret = 1;
	FOR(i, 1, m) {
		LL a = (n + i - m) % p;
		LL b = i % p;
		ret = ret * (a * Quick_mod(b, p - 2) % p) % p;
	}
	return ret;
}
// Lucas(n, m) = Cm(n % p, m % p) * Lucas(n / p, m / p) % p;
LL Lucas(LL n, LL m) {
	if(!m) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%lld%lld%lld", &n, &m, &p);
    	printf("%lld\n", Lucas(n, m));
    }
    
    return 0;
}