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
int n, m, k;
LL a[N], r[N];

// Imp
void exgcd(LL a, LL b, LL & d, LL &x, LL &y) {
	if(b == 0) {
		d = a; x = 1; y = 0;
	} else {
		exgcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

LL Inv(LL a, LL b) {
	LL gcd = __gcd(a, b), d;
	if(gcd != 1) return -1;
	LL x, y;
	exgcd(a, b, d, x, y);
	return (x % b + b) % b;
}

bool merge(LL a1, LL m1, LL a2, LL m2) {
	LL gcd = __gcd(m1, m2), c = a2 - a1;
	if(c % d) return false;
	c = (c % m2 + m2) % m2;
	m1 /= gcd, m2 /= gcd, c /= gcd;
}


#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(k) != EOF) {

    }
    
    return 0;
}