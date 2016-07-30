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
const int inf = 0x3f3f3f3f, N = 10 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char s[N];
int dp[5005];
int dfs(int s) {
    int& ret = dp[s];
    if(ret < inf) return ret;
    ret = __builtin_popcount(s);
    rep(i, 12) {
        if((s & (1 << i)) && (s & (1 << (i + 1))) && !(s & (1 << (i + 2)))) {
            int newState = s - (1 << i) + (1 << (i + 1)) + (1 << (i + 2));
            ret = min(ret, dfs(newState));
        }
        if(!(s & (1 << i)) && (s & (1 << (i + 1))) && (s & (1 << (i + 2)))) {
            int newState = s + (1 << i) - (1 << (i + 1)) - (1 << (i + 2));
            ret = min(ret, dfs(newState));
        }
    }
    return ret;
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        scanf("%s", s);
        n = strlen(s);
        int state = 0;
        for(int i = 0; i < n; i ++)
            if(s[i] == 'o') state += (1 << i);
        
        mem(dp, 0x3f);
        printf("%d\n", dfs(state));
    }
    
    return 0;
}