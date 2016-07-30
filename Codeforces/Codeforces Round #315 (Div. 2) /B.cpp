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
const int inf = 1 << 30, N = 1e5 + 5, MOD = 1e9 + 7;

int n, a[N], flag[N];
VI v;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(n);
    mem(flag, 0);
    rep(i, n) { si(a[i]); flag[a[i]] ++; }
    FOR(i, 1, n) if(flag[i] == 0) v.pb(i);
    int idx = 0;
    rep(i, n) {
    	if(flag[a[i]] > 1 || a[i] > n) {
    		flag[a[i]] --;
    		a[i] = v[idx++];
    	}
    }
    rep(i, n - 1) printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    
    return 0;
}