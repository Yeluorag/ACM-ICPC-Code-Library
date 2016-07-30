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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
LL n;
// Imp

LL Pow(LL a, LL n) {
    if(n == 0) return 1;
    LL x = Pow(a, n / 2);
    LL ans = LL(x) * x % MOD;
    if(n & 1) ans = ans * a %MOD;
    return (LL) ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //    freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> n;
    LL res;
    res = (((Pow(2, n) + 1) % MOD) * (Pow(2, n - 1) % MOD)) % MOD;
    if(n == 0) res = 1;
    cout << res << endl;
    
    return 0;
}