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
const int inf = 0x3f3f3f3f, N = 2e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k, x;
int a[N], l[N], r[N];
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(siii(n, k, x) != EOF) {
        mem(l, 0);
        mem(r, 0);
        FOR(i, 1, n) si(a[i]);
        FOR(i, 1, n) l[i] = l[i - 1] | a[i];
        LL m = 1, ans = 0;
        rep(i, k) m *= (LL)x;
        for(int i = n; i >= 1; i --) r[i] = r[i + 1] | a[i];
        FOR(i, 1, n) {
        	LL tmp = l[i - 1] | r[i + 1];
        	LL t = (LL)a[i] * m;
        	tmp |= t;
        	ans = max(ans, tmp);
        }
        cout << ans << endl;
        
    }
    
    
    return 0;
}