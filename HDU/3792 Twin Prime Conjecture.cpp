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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, ans[N];

// Imp
bool vis[N+1];
vector<int>primes;
void init_primes() {
    mem(vis, 0);
    int m = sqrt(N + 0.5);
    FOR(i, 2, m) if(!vis[i])
        for(int j = i * i; j <= N; j += i) vis[j] = 1;
    FOR(i, 2, N) if(!vis[i])
        primes.pb(i);
}

void init() {
    int idx = 0, sz = primes.size();
    ans[0] = 0;
    REP(i, 1, N) {
        ans[i] = ans[i-1];
        if(i == primes[idx]) {
            if(idx && primes[idx] - primes[idx-1] == 2) ans[i] ++;
            idx ++;
            if(idx >= sz) break;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init_primes();
    init();
    while(si(n) != EOF && n >= 0) {
        put(ans[n]);
    }
    
    return 0;
}