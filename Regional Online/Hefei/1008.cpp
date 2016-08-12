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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const int st = 40;
int T, cas = 0;
int n, m;
int s1, s2;
LL d;
int b[41];
// Imp
bool check(LL n) {
    if(__builtin_popcount(n) < s1 || __builtin_popcount(n) > s2) return false;
    return true;
}
void init(LL n) {
    int t = n, idx = 0;
    mem(b, 0);
    while(t > 0) {
        b[idx++] = t % 2;
        t /= 2;
    }
}
LL cal() {
    LL ret = 0, t = 1;
    for(int i = 0; i < st; i ++) {
        ret += t * b[i];
        t <<= 1;
    }
    return ret;
}

void solve() {
    int n = __builtin_popcount(d), pos = -1, cnt = 0, flag = 0, res = s2 - n;
    rep(i, st) {
        if(b[i] == 1) { b[i] = 0; cnt ++; flag = 1; }
        else if(b[i] == 0) {
            if(flag) {
                pos = i;
                break;
            } else {
                if(res > 0) {
                    b[i] = 1;
                    break;
                }
            }
        }
    }
    if(pos == -1) return;
    int l = n - cnt + 1;
    b[pos] = 1;
    cnt = 0;
    rep(i, pos) {
        if(cnt >= s1 - l) break;
        b[i] = 1;
        cnt ++;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        scanf("%lld%d%d", &d, &s1, &s2);
        init(d);
        solve();
        LL ans = cal();
        if(!check(ans)) ans = d;
        printf("Case #%d: %lld\n", ++ cas, ans);
    }
    
    return 0;
}