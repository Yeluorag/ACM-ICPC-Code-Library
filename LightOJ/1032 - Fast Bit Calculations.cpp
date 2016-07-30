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
const int inf = 0x3f3f3f3f, N = 50 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
LL dp[N][2];
void init() {
    for(int i = 2; i < 32; i ++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i][0] + (1 << (i - 2));
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    si(T);
    while(T --) {
        si(n);
        LL ans = 0, cnt = 0;
        for(int i = 31; i >= 0; i --) {
            if(n & (1 << i)) {
                ans += dp[i+1][0] + cnt * (1 << i);
                if((1 << (i + 1)) & n) cnt ++;
            }
        } 
        ans += cnt;
        printf("Case %d: %lld\n", ++ cas, ans);
    }
    
    return 0;
}
/*
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
const int inf = 0x3f3f3f3f, N = 50 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
LL dp[N][2], digit[N], num;
LL dfs(int i, int k, bool flag) {
    if(i == 1) return 0;
    LL& ret = dp[i][k], tmp = 0;
    if(!flag && ~ret) return ret;

    int ed = flag ? digit[i-1] : 1;
    for(int j = 0; j <= ed; j ++) {
        bool ok = (flag && j == ed);
        tmp += dfs(i - 1, j, ok);
        if(j == 1 && k == 1) {
            if(ok) tmp += num % (1 << (i - 2)) + 1;
            else tmp += (1 << (i - 2));
        }
    }
    if(!flag) ret = tmp;
    return tmp;
}

LL cal(LL x) {
    int len = 0;
    num = x;
    while(x) {
        digit[++ len] = x & 1;
        x >>= 1;
    }
    return dfs(len + 1, 0, 1);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	mem(dp, -1);
    si(T);
    while(T --) {
    	si(n);
        printf("Case %d: %lld\n", ++ cas, cal((LL)n));
    }
    
    return 0;
}
*/