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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
struct node{
	int h, g;
	bool operator < (const node &rhs) const {
		return h * rhs.g < rhs.h * g; 
	}
}a[N];
int v;
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	LL ans = 0, sum = 0;
    	rep(i, n) {
    		sii(a[i].h, a[i].g);
    		a[i].h = (a[i].h + m - 1) / m;
    		sum += a[i].g;
    	}
    	sort(a, a + n);
    	rep(i, n) {
    		ans += a[i].h * sum;
    		sum -= a[i].g;
    	}
    	printf("Case #%d: %lld\n", ++ cas, ans);
    }
    
    return 0;
}