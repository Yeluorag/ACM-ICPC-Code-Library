#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 1e5 + 5, MOD = 1e9 + 7;

LL n, m, T;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    LL res = 0, a, b ;
    cin >> n >> m >> a >> b >> T;
    while (T --) {
        LL x, y, s = inf;
        cin >> x >> y ;
        if (x > 0) s = min (s, (n - a) / x);
        if (x < 0) s = min (s, (a - 1) / -x);
        if (y > 0) s = min (s, (m - b) / y);
        if (y < 0) s = min (s, (b - 1) / -y);
        res += s, a += x * s, b += y * s ;
    }
    cout << res << endl ;
    
    return 0;
}