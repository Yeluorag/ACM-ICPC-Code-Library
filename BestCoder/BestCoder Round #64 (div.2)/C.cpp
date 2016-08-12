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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 100 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n;
LL m, p[60];
int a[N], b[N], tot;
LL sum(LL x) {
    if(x == 1) return 0;
    if(x == 2) return 1;
    return sum(x / 2) * 2 + x / 2;
}
void ex(LL x) {
    tot = 0;
    while(x) {
        a[tot++] = x % 2;
        x /= 2;
    }
}
void init() {
    p[0] = 1;
    for(int i = 1; i < 60; i ++) p[i] = p[i-1] * 2;
}
LL work(LL x) {
    ex(x);
    LL cnt = 0, ans = 0;
    for(int i = tot - 1; i >= 0; i --) {
        if(a[i] == 1) {
            ans += sum(p[i]) + cnt * p[i];
            cnt ++;
        }
    }
    return ans;
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    // freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    si(T);
    while(T --) {
        scanf("%lld", &m);
        printf("%lld\n", work(m + 1));
    }
    return 0;
}