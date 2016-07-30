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
const int inf = 0x3f3f3f3f, N = 400 + 5, MOD = 1e9 + 7;

int n, T, m1, m2, d[N], e[N], t[N];
int cas = 0, dp[405][N], train[405][N][2];

void input() {
    mem(t, 0);
    mem(d, 0);
    mem(e, 0);
    scanf("%d", &T);
    FOR(i, 2, n) scanf("%d", &t[i]);
    scanf("%d", &m1);
    rep(i, m1) scanf("%d", &d[i]);
    scanf("%d", &m2);
    rep(i, m2) scanf("%d", &e[i]);
}
void init()
{
    rep(i, n) dp[T][i] = inf;
    dp[T][n] = 0;
    mem(train, 0);
    rep(i, m1) {
        int time = d[i];
        FOR(j, 1, n) {
            time += t[j];
            train[time][j][0] = 1;
        }
    }
    
    rep(i, m2) {
        int time = e[i];
        for(int j = n; j >= 1; j --){
            time += t[j+1];
            train[time][j][1] = 1;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(scanf("%d", &n), n) {
        input();
        init();
        for(int i = T - 1; i >= 0; i --) {
            FOR(j, 1, n) {
                dp[i][j]=dp[i+1][j]+1;
                if(j < n && i + t[j+1] <= T && train[i][j][0])
                    dp[i][j] = min(dp[i][j], dp[i+t[j+1]][j+1]);
                
                if(j > 1 && i + t[j] <= T && train[i][j][1])
                    dp[i][j] = min(dp[i][j], dp[i+t[j]][j-1]);
            }  
        }
        printf("Case Number %d: ", ++ cas);
        if(dp[0][1] >= inf) puts("impossible");
        else cout << dp[0][1] << endl;
    }    
    
    return 0;
}