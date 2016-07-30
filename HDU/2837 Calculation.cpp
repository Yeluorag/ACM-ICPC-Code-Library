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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int Phi[N];
// Imp
int Euler_Phi(int n) {
	int ret = n, m = (int)sqrt(n + 0.5);
	FOR(i, 2, m) if(n % i == 0) {
		ret = ret / i * (i - 1);
		while(n % i == 0) n /= i;
	} if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

void Phi_Table(int n, int * phi) {
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

LL cal(LL a, LL t, int m) {
	LL ret = 1;
	rep(i, t) {
		ret *= a;
		if(ret >= m) return ret;
	}
	return ret;
}

LL Pow(LL a, LL t, int m) {
	if(t == 0) return 1;
	LL x = Pow(a, t / 2, m);
	LL ans = x * x % m;
	if(t & 1) ans = ans * a % m;
	return ans;
}

LL f(LL n, int num) {
	if(n == 0) return 1;
	LL t = f(n / 10, num + 1);
	LL x = cal(n % 10, t, Phi[num]);
	if(x >= Phi[num])
		return Pow(n % 10, t, Phi[num]) + Phi[num];
	return x;
}
void init(int m) {
	Phi[0] = m;
	REP(i, 1, N) Phi[i] = Euler_Phi(Phi[i-1]);
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	init(m);
    	cout << f((LL)n, 0) % Phi[0] << endl;
    }
    
    return 0;
}