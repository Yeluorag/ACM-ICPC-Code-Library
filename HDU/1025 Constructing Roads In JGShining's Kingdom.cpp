// Header. nlogn LIS
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
const int inf = 0x3f3f3f3f, N = 5e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, d[N];
struct node{
    int p, r;
}a[N];
bool cmp(node r, node s) { return r.p < s.p; }
// Imp

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(si(n) != EOF) {
        int ans = 0;
        rep(i, n) sii(a[i].p, a[i].r);
        sort(a, a + n, cmp);
        d[ans] = a[0].r;
        REP(i, 1, n) {
            if(a[i].r > d[ans]) d[++ans] = a[i].r;
            else {
                int l = 0, r = ans, mid;
                while(l < r) {
                    mid = (l + r) >> 1;
                    if(a[i].r > d[mid]) l = mid + 1;
                    else r = mid;
                }
                d[r] = a[i].r;
            }
        }
        printf("Case %d:\n", ++ cas);
        if(!ans) printf("My king, at most %d road can be built.\n\n", ans + 1);
        else printf("My king, at most %d roads can be built.\n\n", ans + 1);
    }
    
    return 0;
}