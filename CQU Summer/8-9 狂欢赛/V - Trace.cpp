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
const int inf = 1 << 30, N = 1e2 + 5, MOD = 1e9 + 7;
const double pi = 3.1415926536;

int n;
double ans = 0, a[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(n);
    rep(i, n) scanf("%lf", &a[i]);
    sort(a, a + n);
    if(n & 1) {
    	ans += pi * a[0] * a[0];
    	for(int i = 2; i < n; i += 2)
    		ans += pi * (a[i] * a[i] - a[i-1] * a[i-1]);
    } else {
    	for(int i = 1; i < n; i += 2)
    		ans += pi * (a[i] * a[i] - a[i-1] * a[i-1]);
    }
    printf("%.10lf\n", ans);
    return 0;
}