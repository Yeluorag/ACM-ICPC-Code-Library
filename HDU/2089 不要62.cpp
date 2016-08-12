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
const int N = 1e1;

int dp[N][N], a[N];
int n, m;

void init() {
    mem(dp, 0); dp[0][0] = 1;
    FOR(i, 1, 10) rep(j, 10) rep(k, 10)
    if(j != 4 && !(j == 6 && k == 2))
        dp[i][j] += dp[i-1][k];
}

int cal(int x) {
    int len = 0;
    int ret = 0;
    while(x) {
        a[++len] = x % 10;
        x /= 10;
    } a[len+1] = 0;
    for(int i = len; i > 0; i --) {
        rep(j, a[i]) {
            if(j != 4 && !(j==2 && a[i+1] == 6))
                ret += dp[i][j];
        }
        if(a[i] == 4 || (a[i+1] ==6 && a[i] == 2)) break;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    while(scanf("%d%d", &n, &m) && n && m) {
        cout << (cal(m+1) - cal(n)) << endl;
    }
    
    return 0;
}