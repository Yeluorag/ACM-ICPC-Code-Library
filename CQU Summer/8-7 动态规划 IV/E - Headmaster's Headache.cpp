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
const int inf = 1 << 25, N = 2e2 + 5, MOD = 1e9 + 7;

int s, m, n;
int c[N], st[N], d[N][1 << 9][1 << 9];
string str;

int dfs(int i, int s0, int s1, int s2) {
    if(i == m + n) return s2 == (1 << s) - 1 ? 0 : inf;
    int& ans = d[i][s1][s2];
    if(ans >= 0) return ans;
    ans = inf;
    if(i >= m) ans = dfs(i + 1, s0, s1, s2);
    int m0 = st[i] & s0, m1 = st[i] & s1;
    s0 ^= m0; s1 =(s1 ^ m1) | m0; s2 |= m1;
    ans = min(ans, c[i] + dfs(i + 1, s0, s1, s2));
    return ans;
}
// #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(si(s), s) {
        sii(m, n);
        mem(d, -1);
        mem(st, 0);
        int t;
        getchar();
        rep(i, m + n) {
            getline(cin, str);
            stringstream ss;
            ss.str(str);
            ss >> t;
            c[i] = t;
            while(1) {
                ss >> t;
                if(ss.fail()) break;
                st[i] |= 1 << (t - 1);
            }
        }
        printf("%d\n", dfs(0, (1 << s) - 1, 0, 0));
    }
    
    return 0;
}