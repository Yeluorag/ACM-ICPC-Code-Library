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
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define repd(i,n) for(int i = (n-1); i >= 0; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 3e2 + 5, MOD = 1e9 + 7;

int n, x, y, z, idx, ans, cas = 0, dp[N];
struct node{
	int x, y, z;
	void init(int a, int b, int c) {
		x = a; y = b; z = c;
	}
}a[N];

bool cmp(node a, node b) { return a.x * a.y < b.x * b.y; }
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(scanf("%d", &n), n) {
    	idx = 0; ans = 0;
    	rep(i, n) {
    		scanf("%d%d%d", &x, &y, &z);
    		a[idx++].init(x, y, z);a[idx++].init(x, z, y);
    		a[idx++].init(y, x, z);a[idx++].init(y, z, x);
    		a[idx++].init(z, x, y);a[idx++].init(z, y, x);
    	}sort(a, a + idx, cmp);
    	rep(i, idx) {
    		dp[i] = a[i].z;
    		rep(j, i) if(a[i].x > a[j].x && a[i].y > a[j].y)
    			dp[i] = max(dp[i], dp[j] + a[i].z);
    			ans = max(dp[i], ans);
    	}
    	printf("Case %d: maximum height = %d\n", ++ cas, ans);
    }
    
    return 0;
}