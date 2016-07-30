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
const int inf = 0x3f3f3f3f, N = 10 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, tot;
LL a[N];
LL ans = 0;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a * b / gcd(a, b); }
void Inclusion_Exclusion(int idx, LL lcm, int cnt) {
	lcm = a[idx] * lcm / gcd(a[idx], lcm);
	if(cnt & 1) ans += (n - 1) / lcm;
	else ans -= (n - 1) / lcm;
	for(int i = idx + 1; i < tot; i ++)
		Inclusion_Exclusion(i, lcm, cnt + 1);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	int x;
    	tot = ans = 0;
    	for(int i = 0; i < m; i ++) {
    		si(x);
    		if(x) a[tot++] = x;
    	}
    	for(int i = 0; i < tot; i ++) Inclusion_Exclusion(i, a[i], 1);
    	printf("%lld\n", ans);
    }
    
    return 0;
}