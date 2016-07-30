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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
typedef double db;
// Macro end

int T, cas = 0;
int n, m;
double s, a, b, c;
// Imp
double Pow(double t, int n) {
	double ret = 1;
	if(n == 0) return ret;
	if(t == 0) return 0;
	rep(i, n) ret *= t;
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    cin >> s >> a >> b >> c;
    if(a + b + c < 1e-6) printf("%.12lf 0 0\n", s);
    else printf("%.12lf %.12lf %.12lf\n", s * a / ( a + b + c), s * b / ( a + b + c), s * c / ( a + b + c));
    
    return 0;
}