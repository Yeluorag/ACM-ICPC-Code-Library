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
int n;
LL a[N], m, ans;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a * b / gcd(a, b); }
void Inclusion_Exclusion(int idx, LL lcm, int cnt) {
	lcm = a[idx] * lcm / gcd(a[idx], lcm);
	if(cnt & 1) ans += m / lcm;
	else ans -= m / lcm;
	for(int i = idx + 1; i < n; i ++)
		Inclusion_Exclusion(i, lcm, cnt + 1);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%d%lld", &n, &m) != EOF) {
    	for(int i = 0; i < n; i ++) scanf("%lld", &a[i]);
    	ans = 0;
    	for(int i = 0; i < n; i ++)
    		Inclusion_Exclusion(i, a[i], 1);
    	printf("%lld\n", ans);
    }
    
    return 0;
}