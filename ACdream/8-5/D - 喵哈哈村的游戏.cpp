#define LOCAL
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
const int N = 2e1 + 5;

int dp[N][N], n, k, l;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//    freopen("/Users/apple/out.txt", "w", stdout);
#endif

    scanf("%d%d%d", &n, &k, &l);
    mem(dp, 0);
    int t = min(k, l);
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= t; j ++) {
            for(int m = 0; m <= t; m ++) {
                if(j == k) dp[i][j+m] = dp[i][j] + 1;
                else if(j + m == k) dp[i][j+m] = dp[i][j] + 1;
                else dp[i][j+m] = dp[i][j];
            }
        }
    }
    printf("%d\n", dp[n][k]);
    return 0;
}