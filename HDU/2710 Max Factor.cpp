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
const int inf = 0x3f3f3f3f, N = 2e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, a;
// Imp
int vis[N+1];
vector<int> primes;
void init_primes() {
    mem(vis, 0);
    int m = sqrt(N + 0.5);
    FOR(i, 2, m) if(!vis[i])
        for(int j = i * i; j <= N; j += i) vis[j] = 1;
    FOR(i, 2, N) if(!vis[i])
        primes.pb(i);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init_primes();
    int sz = primes.size();
    while(si(n) != EOF) {
        int mxp = 0, mxn = 1;
        rep(i, n) {
            si(a);
            int tmp = 0;
            rep(j, sz) {
                if(primes[j] > a) break;
                if(a % primes[j] == 0) tmp = primes[j];
            }
            if(tmp > mxp) {
                mxn = a;
                mxp = tmp;
            }
        }
        put(mxn);
    }
    return 0;
}