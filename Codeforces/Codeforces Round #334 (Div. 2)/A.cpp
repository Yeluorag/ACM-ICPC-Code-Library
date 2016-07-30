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
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n;
int m[6], w[6], hs, hu;
int s[6] = { 500, 1000, 1500, 2000, 2500 };
int ans;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    rep(i, 5) si(m[i]);
    rep(i, 5) si(w[i]);
    sii(hs, hu);
    ans = 0;
    rep(i, 5) {
        int tmp = max(s[i] / 10 * 3, s[i] - m[i] * s[i] / 250 - 50 * w[i]);
        ans += tmp;
    }
    ans += 100 * hs - 50 * hu;
    printf("%d\n", ans);
    
    return 0;
}