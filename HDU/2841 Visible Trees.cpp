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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, sz;
int phi[N];
vector<int> primes[N];
void Phi_Table(int n) {
	mem(phi, 0);
	phi[1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(!phi[i]) {
			for(int j = i; j <= n; j += i) {
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

void primes_init(int n) {
	int m = sqrt(n + 0.5), x = n;
	primes[n].clear();
	for(int i = 2; i <= m; i ++) {
		if(x % i == 0) {
			primes[n].pb(i);
			while(x % i == 0) x /= i;
		}
	} if(x > 1) primes[n].pb(n);
}

int Inclusion_Exclusion(int idx, int b, int n) {
	int ret = 0, tmp, sz = primes[n].size();
	for(int i = idx; i < sz; i ++) {
		tmp = b / primes[n][i];
		ret += tmp - Inclusion_Exclusion(i + 1, tmp, n);
	}
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    Phi_Table(N - 1);
	for(int i = 2; i < N; i ++) primes_init(i);
    si(T);
    while(T --) {
    	sii(n, m);
    	if(n > m) swap(n, m);
    	LL ans = 0;
    	for(int i = 2; i <= n; i ++) ans += (LL)phi[i];
    	ans <<= 1;
    	for(int i = n + 1; i <= m; i ++)
    		ans += (LL)(n - Inclusion_Exclusion(0, n, i));
    	printf("%lld\n", ++ ans);
    }
    
    return 0;
}