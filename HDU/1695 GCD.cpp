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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int a, b, c, d, k;
LL phi[N];
VI pr[N];
// Imp
int euler_phi(int n) {
    int ret = n, m = (int)sqrt(n + 0.5);
    FOR(i, 2, m) if(n % i == 0) {
        ret = ret / i * (i - 1);
        while(n % i == 0) n /= i;
    } if(n > 1) ret = ret / n * (n - 1);
    return ret;
}

void phi_table(int n) {
    mem(phi, 0);
    phi[1] = 1;
    FOR(i, 2, n) {
        if(!phi[i]) {
            for(int j = i; j <= n; j += i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
                pr[j].pb(i);
            }
        }
        phi[i] += phi[i-1];
    }
}

LL Inclusion_exclusion(int idx, int t, int n) {
    LL ret = 0, tmp;
    int sz = pr[n].size();
    REP(i, idx, sz) {
        tmp = t / pr[n][i];
        ret += tmp - cal(i + 1, tmp, n);
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    phi_table(N - 1);
    si(T);
    while(T --) {
        sii(a, b), siii(c, d, k);
        printf("Case %d: ", ++ cas);
        if(b > d) swap(b, d);
        if(!k) {
            puts("0");
            continue;
        }
        LL ans = 0;
        b /= k, d /= k;
        ans = (LL)phi[b];
        FOR(i, b + 1, d) ans += (LL)b - Inclusion_exclusion(0, b, i);
        printf("%I64d\n", ans);
    }
    
    return 0;
}