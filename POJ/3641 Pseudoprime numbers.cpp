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
int n, m;
LL p, a;
// Imp
bool isPrime(LL n) {
	for(LL i = 2; i * i < n; i ++) if(n % i == 0) return false;
	return true;
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

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(cin >> p >> a, p + a) {
    	if(isPrime(p)) puts("no");
    	else {
    		if(quick_mod(a, p, p) == a) puts("yes");
    		else puts("no");
    	}
    }
    
    return 0;
}