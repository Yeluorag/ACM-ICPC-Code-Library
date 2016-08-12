// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
const int inf = 0x3f3f3f3f, N = 3e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, ans;

// Imp
bool g[N][N], used[N];
int link[N];
bool find(int x) {
    FOR(y, 1, m) {
        if(g[x][y] && !used[y]) {
            used[y] = true;
            if(link[y] == -1 || find(link[y])) {
                link[y] = x;
                return true;
            }
        }
    }
    return false;
}
void init() {
    mem(link, -1);
    mem(g, false);
    ans = 1;
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    si(T);
    while(T --) {
        init();
        sii(n, m);
        int c, s;
        FOR(i, 1, n) {
            si(c);
            rep(j, c) {
                si(s);
                g[i][s] = 1;
            }
        }
        FOR(i, 1, n) {
            mem(used, 0);
            if(!find(i)) ans = 0;
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    
    return 0;
}