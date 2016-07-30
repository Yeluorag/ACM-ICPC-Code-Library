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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, d;
struct node {
    int m, s;
}a[N];
// Imp
bool cmp(node p, node q) {
    if(p.m == q.m) return p.s > q.s;
    return p.m < q.m;
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    sii(n, d);
    rep(i, n) sii(a[i].m, a[i].s);
    sort(a, a + n, cmp);
    int l = 0, r = 0;
    LL cnt = a[0].s, ans = 0;
    REP(i, 1, n) {
        if(a[i].m >= a[l].m + d) {
            ans = max(ans, cnt);
            while(a[i].m >= a[l].m + d) {
                cnt -= a[l].s;
                l ++;
            }
        } else {
            cnt += a[i].s;
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}