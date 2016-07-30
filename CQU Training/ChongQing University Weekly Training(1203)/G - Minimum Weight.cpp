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
typedef unsigned long long ull;
#define mem(a, n) memset(a, n, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 41 + 5, MOD = 1e9 + 7;
LL M = 4e18;

int T, cas = 0;
LL n, m;
int k;
ull a[105], b[N], sum[N];
void init() {
    b[0] = 0; b[1] = 1, sum[1] = 1;
    for(int i = 2; i < N; i ++) {
        b[i] = 2 * sum[i-1] + 1;
        sum[i] = sum[i-1] + b[i];
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
// freopen("/Users/acpple/out.txt", "w", stdout);
#endif
    
    init();
    while(scanf("%lld%d", &n, &k), n + k) {
        ull num = 0;
        for(int i = 0; i < k; i ++) { scanf("%llu", &a[i]); num = max(num, a[i]); }
        int tot = lower_bound(sum, sum + N, n) - sum;
        printf("%d", tot);
        for(int i = 1; i <= tot; i ++) printf(" %llu", b[i]); puts("");
        for(int i = 0; i < k; i ++) {
            LL cnt = a[i];
            int flag = 1;
            for(int j = tot; j >= 0; j --) {
                if(cnt == 0) break;
                if(sum[j] < abs(cnt)) {
                    if(flag) {
                        cnt = b[j+1] - cnt;
                        printf("%llu", b[j+1]);
                        flag = 0;
                    } else {
                        printf("%c%llu", cnt < 0 ? '+' : '-', b[j+1]);
                        if(cnt > 0) cnt -= b[j+1];
                        else cnt += b[j+1];
                    }
                }
            }
            puts("");
        }
    }
    
    return 0;
}