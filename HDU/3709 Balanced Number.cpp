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
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
LL l, r;
int bit[20];
LL dp[20][20][N];

LL dfs(int pos, int o, int l, bool flag) {
    if(pos == -1) return l == 0;
    if(l < 0) return 0;
    if(dp[pos][o][l] != -1 && !flag) return dp[pos][o][l];
    LL ret = 0;
    int ed = flag ? bit[pos] : 9;
    for(int i = 0; i <= ed; i ++) {
        int nxt = l;
        nxt += (pos - o) * i;
        ret += dfs(pos - 1, o, nxt, flag && i == ed);
    }
    if(!flag) dp[pos][o][l] = ret;
    return ret;
}

LL cal(LL x) {
    int len = 0;
    while(x) {
        bit[len ++] = x % 10;
        x /= 10;
    }
    LL ret = 0;
    for(int i = 0; i < len; i ++) 
        ret += dfs(len - 1, i, 0, 1);
    return ret - (len - 1);
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    mem(dp, -1);
    while(T --) {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", cal(r) - cal(l - 1));
    }
    
    return 0;
}


