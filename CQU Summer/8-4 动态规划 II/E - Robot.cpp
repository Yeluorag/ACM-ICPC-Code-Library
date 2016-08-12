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
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30;
const int N = 1e5 + 5;

LL n, m, cn, cs, cw, ce, ans;
LL we, ns, a, b, c, d, t;
int cas = 0;

void WE() {
    if(d > 0) {
        t = 2 * c;
        if(c == d) t --;
        else d --;
        d -= c; c = 0;
        ans += t * n * (m - 1) + n * m;
        m --;
    }
}
void NS() {
    if(b > 0) {
        t = 2 * a;
        if(a == b) t --;
        else b --;
        b -= a; a = 0;
        ans += t * (n - 1) * m+ n * m;
        n --;
    }
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(scanf("%lld%lld", &n, &m) && n && m) {
        ans = 0;
        
        scanf("%lld%lld%lld%lld", &cn, &cs, &cw, &ce);
        a = min(cn, cs); b = max(cn, cs);
        c = min(cw, ce); d = max(cw, ce);
        if(n < m) { WE(); NS();}
        else { NS(); WE(); }
        while(n && m && (b || d)) {
            ans += n * m;
            int flag = -1;
            if(n > m) flag = (b > 0);
            else flag = (d == 0);
            if(flag) { b --; n --; }
            else { d --; m --; }
        }
        printf("Case %d: %lld\n", ++ cas, ans);
    }
    
    return 0;
}