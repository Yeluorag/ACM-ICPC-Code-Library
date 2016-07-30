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

int n, l[N], r[N], ul, ur, cas = 0;
LL a[N], sum[N], ans, tmp;

void init() {
    ul = ur = 1;
    ans = 0; tmp = 0;
    FOR(i, 1, n) if(a[i] > 0) while(a[l[i]-1] >= a[i]) { l[i] = l[l[i]-1]; }
    for(int i = n; i >= 1; i --) if(a[i] > 0) while(a[r[i]+1] >= a[i]) { r[i] = r[r[i]+1]; }
}

void solve() {
    init();
    FOR(i, 1, n) {
        if(a[i] > 0){
            tmp = a[i] * (sum[r[i]] - sum[l[i]-1]);
            if(tmp > ans) {
                ans = tmp;
                ul = l[i];
                ur = r[i];
            } else if(tmp == ans) {
                if(ur - ul == r[i] - l[i] && l[i] < ul) { ul = l[i]; ur = r[i]; }
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(scanf("%d", &n) == 1) {
        if(cas ++) ET;
        sum[0] = 0;
        mem(a, 0);
        FOR(i, 1, n) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i-1] + a[i];
            l[i] = r[i] = i;
        }
        solve();
        printf("%lld\n%d %d\n", ans, ul, ur);
    }
    
    return 0;
}