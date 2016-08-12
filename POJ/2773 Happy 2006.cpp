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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const LL INF = 1e16;

int T, cas = 0;
int n, m, k, sz;
bool vis[N];
vector<int>primes;
void primes_init(int n) {
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

LL Inclusion_Exclusion(int idx, LL num) {
	LL ret = 0, tmp;
	for(int i = idx; i < sz; i ++) {
		tmp = num / primes[i];
		ret += tmp - Inclusion_Exclusion(i + 1, tmp);
	}
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	

    while(sii(n, k) != EOF) {
    	primes_init(n);
    	LL l = 0, r = INF;
    	while(l < r - 1) {
    		LL mid = (l + r) >> 1;
    		LL cnt = mid - Inclusion_Exclusion(0, mid);
    		if(cnt < k) l = mid;
    		else r = mid;
    	}
    	printf("%lld\n", r);

    }

    return 0;
}