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
const int inf = 0x3f3f3f3f, N = 2e7 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int a, b;
int sz = 0;
// Imp
bool vis[N+1];
bool pf[155];
int primes[1500000];
void init_primes() {
    mem(vis, 0);
    mem(pf, 0);
    int m = sqrt(N + 0.5);
    FOR(i, 2, m) if(!vis[i])
        for(int j = i * i; j <= N; j += i) vis[j] = 1;
    int last = 2;
    FOR(i, 2, N) if(!vis[i]){
        primes[sz++] = i;
        if(i > 2) {
            pf[i-last] = 1;
            last = i;
        }
    }
}

int solve() {
    int ret = -1;
    int c = min(a, b), d = max(a, b);
    if(c == d || !pf[d-c]) return ret;
    if(pf[d-c]) {
        rep(i, sz - 1) {
            if(primes[i+1] - primes[i] == d - c && primes[i] >= c) {
                return ret = primes[i] - c;
            }
        }
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init_primes();
    si(T);
    while(T --) {
        int ans = -1;
        sii(a, b);
        ans = solve();
        printf("Case %d: %d\n", ++ cas, ans);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    return 0;
}