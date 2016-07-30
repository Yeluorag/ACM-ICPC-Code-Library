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
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int vis[N], len;
LL l, r, ans;
vector<LL> primes;

void primes_init() {
    mem(vis, 0);
    int m = 1000;
    FOR(i, 2, m) if(!vis[i])
        for(int j = i * i; j <= N; j += i) vis[j] = 1;
    FOR(i, 2, N) if(!vis[i]) primes.pb(i);
    len =primes.size();
}


//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    primes_init();
    si(T);
    while(T --) {
        ans = 0;
        scanf("%lld%lld", &l, &r);
        rep(i, len) {
            LL tmp = primes[i] * primes[i];
            while(tmp < l) tmp *= primes[i];
            if(tmp > r) break;
            while(tmp <= r && tmp >= l) {
                ans ++;
                tmp *= primes[i];
            }
        }
        printf("%lld\n", ans);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}