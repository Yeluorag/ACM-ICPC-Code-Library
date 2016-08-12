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
const int inf = 0x3f3f3f3f, N = 35000 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int len, l, r, vis[N];
VI primes;

int cal(int n) {
    int ret = 1;
    rep(i, len) {
        if(n == 1) break;
        if(primes[i] > n) break;
        int cnt = 1;
        while(n % primes[i] == 0) cnt ++, n /= primes[i];
        ret *= cnt;
    }
    return ret;
}

void init_primes() {
    mem(vis, 0);
    int m = sqrt(N + 0.5);
    FOR(i, 2, m) if(!vis[i])
        for(int j = i * i; j <= N; j += i) vis[j] = 1; 
    FOR(i, 2, N) if(!vis[i])
    primes.pb(i);
    len = primes.size();
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(T);
    while(T --) {
        int ans = inf, num = -1;
        sii(l, r);
        FOR(i, l, r) {
            int t = cal(i);
            if(t > num) ans = i, num = t;
        }
        if(l * r == 1) ans = num = 1;
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, ans, num);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}