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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 3e3 + 5, MOD = 10000007;

int T, cas = 0;
int n, m, a[1005], b[1005];
int dp[1005][1005];
map<string, int> mp;
int cnt = 0;
int ID(string &s) {
    if(mp.count(s)) return mp[s];
    mp[s] = ++ cnt;
    return cnt;
}
char s1[N], s2[N];

string s, t;
int p[N];
void init() {
    p[0] = 1;
    for(int i = 1; i < 2001; i ++) p[i] = (p[i-1] * 2) % MOD;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    si(T);
    while(T --) {
        
        cin >> s >> t;
        s += 'A'; t += 'A';
        cnt = n = m = 0; mp.clear();
        string tmp;
        for(int i = 0; i < s.size(); ++i) {
            if(isalpha(s[i])) {
                if(tmp.size()) {
                    a[++ n] = ID(tmp);
                    tmp.clear();
                }
            }
            tmp += s[i];
        }
        
        tmp.clear();
        for(int i = 0; i < t.size(); ++i) {
            if(isalpha(t[i])) {
                if(tmp.size()) {
                    b[++ m] = ID(tmp);
                    tmp.clear();
                }
            }
            tmp += t[i];
        }
        
        mem(dp, 0);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(a[i] == b[j])  dp[i][j] = (dp[i-1][j-1] * 2 + 1) % MOD;
                else  dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % MOD;
            }
        }
        int sum = (p[n] + p[m] - 2 - dp[n][m] * 2 + MOD) % MOD;
        printf("Case %d: %d\n", ++ cas, (sum + MOD) % MOD);
    }
    
    return 0;
}