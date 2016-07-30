// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
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
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
#define ALL(v) v.begin(), v.end()
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, M = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, cnt[M];
char dna[M][N];
// Imp

 
void init() {
    sii(m, n);
    rep(i, m) ss(dna[i]);
}
 
void solve() {
    int ans = 0;
    rep(i, n) {
        int Max = 0, id;
        memset(cnt, 0, sizeof(cnt));
        rep(j, m) {
            int tmp = dna[j][i] - 'A';
            cnt[tmp]++;
            if (cnt[tmp] > Max) {
                Max = cnt[tmp];
                id = tmp;
            } else if (cnt[tmp] == Max && tmp < id)
                id = tmp;
        }
        ans += m - Max;
        printf("%c", 'A' + id);
    } puts("");
    put(ans);
}

int main() {
#ifdef LOCAL
	IN
#endif
    int cas;
    si(cas);
    while (cas--) {
        init();
        solve();
    }
    return 0;
}