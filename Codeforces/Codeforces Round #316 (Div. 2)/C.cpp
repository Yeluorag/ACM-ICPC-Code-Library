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
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 3e5 + 5, MOD = 1e9 + 7;

int n, m, len, now = 0;
char s[N];

void query() {
    int t; char c;
    getchar();
    scanf("%d %c", &t, &c); t --;
    if(s[t] == '.') {
        if(c != '.') {
            if(t < len - 1 && s[t+1] == '.') now --;
            if(t > 0 && s[t-1] == '.') now --;
        }
    } else {
        if(c == '.') {
            if(t < len -1 && s[t+1] == '.') now ++;
            if(t > 0 && s[t-1] == '.') now ++;
        }
    }
    s[t] = c;
    printf("%d\n", now);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    sii(n, m);
    ss(s);
    mem(l, -1); mem(r, -1);
    len = strlen(s);
    rep(i, len - 1) if(s[i] == '.' && s[i+1] =='.') now ++;
    rep(i, m) query();
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}