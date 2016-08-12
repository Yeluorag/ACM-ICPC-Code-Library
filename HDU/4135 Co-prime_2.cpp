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
const int inf = 0x3f3f3f3f, N = 1e9 + 5, MOD = 1e9 + 7;

int T, cas = 0;
LL n, l, r, ans[2];
int sz;
vector<int>primes;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
void PrimesInit(int n) {
	primes.clear();
	int m = sqrt(n + 0.5);
	for(int i = 2; i <= m; i ++) {
		if(n % i == 0) {
			primes.pb(i);
			while(n % i == 0) n /= i;
		}
	} if(n > 1) primes.pb(n);
	sz = primes.size();
}
void Inclusion_Exclusion(int idx, LL lcm, LL cnt, int t, LL num) {
	lcm = primes[idx] * lcm / gcd(primes[idx], lcm);
	if(cnt & 1) ans[t] += num / lcm;
	else ans[t] -= num / lcm;
	for(int i = idx + 1; i < sz; i ++)
		Inclusion_Exclusion(i, lcm, cnt + 1, t, num);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%lld%lld%lld", &l, &r, &n);
    	// printf("(%d, %d)\n", l, r);
    	PrimesInit(n);
    	mem(ans, 0);
    	for(int i = 0; i < sz; i ++) {
    		Inclusion_Exclusion(i, primes[i], 1, 0, l - 1);
    		Inclusion_Exclusion(i, primes[i], 1, 1, r);
    	}
    	ans[0] = l - 1 - ans[0], ans[1] = r - ans[1];
    	printf("Case #%d: %lld\n", ++ cas, ans[1] - ans[0]);
    }
    
    return 0;
}