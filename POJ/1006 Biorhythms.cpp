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
int n;
int a[5], m[5];

// Imp
void exgcd(int a, int b, int &d, int &x, int &y) {
	if(b == 0) {
		d = a, x = 1, y = 0;
	} else {
		exgcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

int CRT(int a[], int m[], int n) {
	int M = 1, ans = 0;
	FOR(i, 1, n) M *= m[i];
	FOR(i, 1, n) {
		int x, y, d;
		int Mi = M / m[i];
		exgcd(Mi, m[i], d, x, y);
		ans = (ans + Mi * x * a[i]) % M;
	}
	if(ans < 0) ans += M;
	return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	m[1] = 23, m[2] = 28, m[3] = 33;
	int p, e, i, d;
	while(cin >> p >> e >> i >> d, p + e + i + d + 4) {
		a[1] = p, a[2] = e, a[3] = i;
		int ans = CRT(a, m, 3);
		if(ans <= d) ans += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++ cas, ans - d);
	}
    
    return 0;
}