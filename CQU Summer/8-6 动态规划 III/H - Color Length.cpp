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
const int inf = 1 << 30, N = 5e4 + 5, MOD = 1e9 + 7;

int T, n, m;
int dp[N][N], cnt[N][N], first[27][2], last[27][2];
char a[N],b[N];

void init(){
    mem(last, -1);
    rep(i, 27) first[i][0] = first[i][1] = inf;
    n = strlen(a);
    m = strlen(b);
    rep(i, n) {
        if(first[a[i]-'A'][0] == inf) first[a[i]-'A'][0] = i;;
        last[a[i]-'A'][0] = i;
    }
    rep(i, m) {
        if(first[b[i]-'A'][1] == inf) first[b[i]-'A'][1] = i;;
        last[b[i]-'A'][1] = i;
    }
    FOR(i, 0, n) {
        int temp = 0, k1 = -1, k2 = -1;
        FOR(j, 0, m) {
            if(i){
                temp = cnt[i-1][0];
                k1 = a[i-1]-'A';
                if(first[k1][0] == i - 1 && first[k1][1] > j - 1) temp ++;
                if(last[k1][0] <= i - 1 && last[k1][1] <= j - 1) temp --;
            }
            if(j){
                temp = cnt[i][j-1];
                k2 = b[j-1]-'A';
                if(first[k2][0] > i - 1 && first[k2][1] == j - 1) temp ++;
                if(last[k2][0] <= i - 1 && last[k2][1] <= j - 1) temp --;
            }
            cnt[i][j] = temp;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    cin >> T;
    while(T --){
        scanf("%s",a);
        scanf("%s",b);
        init();
        dp[0][0] = 0;
        FOR(i, 1, m) dp[0][i] = dp[0][i-1] + cnt[0][i];
        FOR(i, 1, n) dp[i][0] = dp[i-1][0] + cnt[i][0];
        FOR(i, 1, n) FOR(j, 1, m)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cnt[i][j];
        printf("%d\n", dp[n][m]);
    }

    
    return 0;
}