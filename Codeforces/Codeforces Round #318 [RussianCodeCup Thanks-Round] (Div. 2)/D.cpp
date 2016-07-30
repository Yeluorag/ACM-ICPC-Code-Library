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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int a[N], c[N];
// Imp

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    si(n);
    mem(c, 0x3f);
    rep(i, n) si(a[i]);
    c[0] = c[n-1] = 0;
    int k = 0;
    REP(i, 1, n) {
        Min(c[i], a[i] - 1);
        if(a[i-1] >= a[i]) {
            if(a[i] - 1 > 0) Min(c[i], c[i-1] + 1);
            else c[i] = 0;
        } else {
            if(a[i-1]) Min(c[i], c[i-1] + 1);
            else c[i] = 0;
        }
        
    }
    for(int i = n - 2; i >= 0; i --) {
        if(a[i+1] >= a[i]) {
            if(a[i] - 1 > 0) Min(c[i], c[i+1] + 1);
            else c[i] = 0;
        } else {
            if(a[i+1]) Min(c[i], c[i+1] + 1);
            else c[i] = 0;
        }
    }int ans = 0;
    rep(i, n) Max(ans, c[i]);
    put(ans + 1);
    return 0;
}