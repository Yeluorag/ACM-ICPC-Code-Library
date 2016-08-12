#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
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
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 2e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int a, b;
int phi[N];
double ans;

void phi_table(int n, int * phi) {
	mem(phi, 0);
	phi[1] = 1;
	FOR(i, 2, n) if(!phi[i]) {
		for(int j = i; j <= n; j += i) {
			if(!phi[j]) phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
	}
}


//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    phi_table(N, phi);
    while(sii(a, b) && a + b) {
    	ans = 0;
    	FOR(i, 1, a) {
    		ans += phi[i] * (b / i);
    		int mod = b % i;
    		FOR(j, 1, mod) ans += __gcd(i, j) == 1;
    	}
    	ans = (ans * 2 + 2) / (double)((LL)a * b * 2 + a + b);
    	printf("%.7lf\n", ans);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}