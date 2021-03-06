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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
LL mod = 1000000007LL;
int T, cas = 0;
int n, m;
LL p[20];
int bit[20];
struct node {
    LL cnt;
    LL sum;
    LL sqsum;
} dp[20][8][8]; //[len][pre1][pre2]: pre1各位数字和模，pre2数模

node dfs(int pos, int pre1, int pre2, bool flag) {
    if(pos == -1) {
        node tmp;
        tmp.cnt = (pre1 != 0 && pre2 != 0);
        tmp.sum = tmp.sqsum = 0;
        return tmp;
    }
    
    if(!flag && dp[pos][pre1][pre2].cnt != -1) 
        return dp[pos][pre1][pre2];
    int ed = flag ? bit[pos] : 9;
    node ret, tmp;
    ret.cnt = ret.sqsum = ret.sum = 0;
    for(int i = 0; i <= ed; i ++) {
        if(i == 7) continue;
        tmp = dfs(pos - 1, (pre1 + i) % 7, (pre2 * 10 + i) % 7, flag && i == ed);
        ret.cnt = (ret.cnt + tmp.cnt) % mod;
        ret.sum = (ret.sum + tmp.sum + ((p[pos] * i) % mod) * tmp.cnt % mod) % mod;
        ret.sqsum = (ret.sqsum + tmp.sqsum + ((2 * p[pos] * i) % mod) * tmp.sum) % mod;
        ret.sqsum = (ret.sqsum + (tmp.cnt * p[pos]) % mod * p[pos] % mod * i * i % mod) % mod;
    }
    if(!flag) dp[pos][pre1][pre2] = ret;
    return ret;

}

LL cal(LL x) {
    int pos = 0;
    while(x) {
        bit[pos ++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, 0, 1).sqsum;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    p[0] = 1;
    for(int i = 1; i < 20; i ++) p[i] = p[i-1] * 10 % mod;
    mem(dp, -1);
    si(T);
    while(T --) {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", (cal(r) - cal(l - 1) + mod) % mod);
    }
    
    return 0;
}
