// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 5e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int f[N+1], ans[N];
// Imp
// Euler Phi Func Model
int euler_phi(int n) {
	int ret = n, m = (int)sqrt(n + 0.5);
	FOR(i, 2, m) if(n % i == 0) {
		ret = ret / i * (i - 1);
		while(n % i == 0) n /= i;
	} if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

void phi_table(int n, int phi[]) {
	mem(phi, 0);
	phi[1] = 1;
	FOR(i, 2, n) {
		if(!phi[i]) {
			for(int j = i; j <= n; j += i) {
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    phi_table(N, f);
    mem(ans, 0);
    FOR(i, 2, N) ans[i] = ans[i-1] + f[i];
    while(si(n), n) {
    	put(2 * ans[n] + 1);
    }
    
    return 0;
}