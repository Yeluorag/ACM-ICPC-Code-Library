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
#define repd(i,n) for(int i = (n-1); i >= 0; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a);
#define sii(a, b) scanf("%d%d", &a, &b);
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 50 + 5, MOD = 1e9 + 7;
const int JQ =  678;

int T, cas = 0;
int n, t, sum, a[N], dp[N*180][2];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    cin >> T;
    while(T --) {
        sii(n, t);
        sum = 0;
        FOR(i, 1, n) { si(a[i]); sum += a[i]; }
        mem(dp, 0);
        t = min(t - 1, sum);
        FOR(i, 1, n) {
            for(int j = t; j >= a[i]; j --) {
                if(dp[j][0] < dp[j-a[i]][0] + 1) {
                    dp[j][1] = dp[j-a[i]][1] + a[i];
                    dp[j][0] = dp[j-a[i]][0] + 1;
                }
                if(dp[j][0] == dp[j-a[i]][0] + 1)
                    dp[j][1] = max(dp[j][1], dp[j-a[i]][1] + a[i]);
            }
        }
        printf("Case %d: %d %d\n", ++ cas, dp[t][0] + 1, dp[t][1] + JQ);
    }
    return 0;
}