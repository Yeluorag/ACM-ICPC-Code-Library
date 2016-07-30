// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
const int inf = 0x3f3f3f3f, N = 2e2 + 5, MOD = 1e8;
// Macro end

int T, cas = 0;
LL a;
int k, Phi[N];

// Imp
int euler_phi(int n) {
	int ret = n, m = (int)sqrt(n + 0.5);
	FOR(i, 2, m) if(n % i == 0) {
		ret = ret / i * (i - 1);
		while(n % i == 0) n /= i;
	} if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

void phi_table(int n, int * phi) {
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


LL Pow(LL a, LL t, int m) {
	if(t == 0) return 1;
	LL x = Pow(a, t / 2, m);
	LL ans = x * x % m;
	if(t & 1) ans = ans * a % m;
	return ans;
}
LL cal(LL a, LL t, int m) {
	LL ret = 1;
	rep(i, t) {
		ret *= a;
		if(ret >= m) return ret;
	}
	return ret;
}
LL Up(LL a, int k, int num) {
	if(Phi[num] == 1) return 1;
	if(k == 1) return a % Phi[num];
	LL t = Up(a, k - 1, num + 1);
	LL x = cal(a, t, Phi[num]);
	if(x >= Phi[num])
		return Pow(a % Phi[num], t, Phi[num]) + Phi[num];
	return x;
}

void init() {
	Phi[0] = MOD;
	REP(i, 1, N) Phi[i] = euler_phi(Phi[i-1]);
}

int main(){
#ifdef LOCAL
    IN  //  OUT
#endif
	
	init();
    while(scanf("%I64d%d", &a, &k) != EOF) {
    	cout << Up(a, k, 0) % Phi[0] << endl;
    }
    return 0;
}