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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, p;
LL fac[N];
// Imp

LL Quick_mod(LL a, LL b, LL p) {
	 LL ret = 1;
	 a %= p;
	 while(b > 0) {
	 	if(b & 1) ret = ret * a % p;
	 	b /= 2;
	 	a = a * a % p;
	 }
	 return ret;
}

void init(LL p) {
	fac[0] = 1;
	FOR(i, 1, p) fac[i] = fac[i - 1] * i % p;
}

LL Cm(LL n, LL m, LL p) {
	if(m > n) return 0;
	return fac[n] * Quick_mod(fac[m] * fac[n - m] % p, p - 2, p) % p;
}

LL Lucas(LL n, LL m, LL p) {
	if(!m) return 1;
	return Cm(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	siii(n, m, p);
    	init(p);
    	cout << Lucas(n + m, m, p) << endl;
    }
    
    return 0;
}