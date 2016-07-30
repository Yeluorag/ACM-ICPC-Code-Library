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
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = (1 << 11) + 5, MOD = 1e9 + 7;

int n, m;
int num[150], d[N][N];
char str[105];

int dfs(int s, int a) {
    if(d[s][a] < inf) return d[s][a];
    int cnt = 0;
    rep(i, n) if((num[i] & s) == a) cnt ++;
    if(cnt <= 1) { d[s][a] = 0; return 0; }
    rep(i, m) {
        if(s & (1 << i)) continue;
        int st = s | (1 << i);
        d[s][a] = min(d[s][a], max(dfs(st, a), dfs(st, a ^ (1 << i))) + 1);
    }
    return d[s][a];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(m, n) && m && n) {
        rep(i, n) {
            scanf("%s", str);
            num[i] = 0;
            rep(j, m) if(str[j] == '1') num[i] |= 1<<j;
        }
        mem(d, 0x3f);
        printf("%d\n", dfs(0, 0));
    }
    
    return 0;
}