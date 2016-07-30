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
const int inf = 0x3f3f3f3f, N = 2e3 + 5;
const LL MOD = 1e9 + 7;

int T, cas = 0;
LL n, m;
int k;
LL C[N][N], B[N], inv[N], tmp[N];
// Imp
void Combo() {

    for(int i = 0; i < N; i ++) {
        C[i][0] = C[i][i] = 1;
        if(i == 0) continue;
        for(int j = 1; j < i; j ++)
            C[i][j] = (C[i-1][j-1] % MOD + C[i-1][j] % MOD) % MOD;
    }
}
void Init() {
    Combo();
    inv[1] = 1;
    for(int i = 2; i < N; i ++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    B[0] = 1;
    for(int i = 1; i < N - 1; i ++) {
        LL ans = 0;
        for(int j = 0; j < i; j ++) {
            ans += C[i + 1][j] * B[j];
            ans %= MOD;
        }
        ans *= -inv[i + 1];
        ans = (ans % MOD + MOD) % MOD;
        B[i] = ans;
    }
}

LL work(int k) {
	LL ans = inv[k + 1], sum = 0;
	FOR(i, 1, k + 1) {
		sum += C[k + 1][i] * tmp[i] % MOD * B[k + 1 - i] % MOD;
		sum %= MOD;
	}
	ans *= sum;
	ans %= MOD;
	return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    Init();
    while(T --) {
    	scanf("%lld %d", &n, &k);
    	n %= MOD;
    	tmp[0] = 1;
    	REP(i, 1, N) tmp[i] = tmp[i - 1] * (n + 1) % MOD;
    	printf("%lld\n", work(k));
    }
    
    return 0;
}