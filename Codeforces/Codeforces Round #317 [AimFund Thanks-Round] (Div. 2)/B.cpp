// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, s, buy[N], sell[N];
struct node1 {
    int p, v;
}b[1005], se[1005];

// Imp


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    mem(buy, 0);
    mem(sell, 0);
    sii(n, s);
    char c;
    int pr, vl;
    
    rep(i, n) {
        getchar();
        scanf("%c %d %d", &c, &pr, &vl);
        if(c == 'B') buy[pr] += vl;
        else sell[pr] += vl;
    }
    int idxs = 0, idxb = 0;
    rep(i, N) {
        if(sell[i] > 0) {
            se[idxs].p = i;
            se[idxs].v = sell[i];
            idxs ++;
        }
    }
    for(int i = 100000; i >= 0; i --) {
        if(buy[i] > 0) {
            b[idxb].p = i;
            b[idxb].v = buy[i];
            idxb ++;
        }
    }
    int k = s;
    if(s > idxs) k = idxs;
    for(int i = k - 1, j = 0; i >= 0 && j < s; i --, j ++)
        printf("S %d %d\n", se[i].p, se[i].v);
    for(int i = 0; i < s && i < idxb; i ++)
        printf("B %d %d\n", b[i].p, b[i].v);
    return 0;
}