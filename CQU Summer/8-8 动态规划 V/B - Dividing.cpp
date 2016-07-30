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
const int inf = 1 << 30, N = 2e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int ans, sum, a[10], dp[N];

void solve() {
	mem(dp, -1);
	dp[0] = 1;
	rep(i, 6) {
		FOR(j, 0, sum) {
			if(dp[j] >= 0) dp[j] = a[i];
			else if(j < (i + 1) || dp[j-i-1] < 0) dp[j] = -1;
			else dp[j] = dp[j-i-1] - 1;
		}
	}
	ans = dp[sum] >= 0;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(1) {
    	if(cas) ET;
    	sum = 0;
    	rep(i, 6) {
    		si(a[i]);
    		sum += a[i] * (i + 1);
    	} if(!sum) break;
    	if(sum & 1) ans = 0;
    	else { sum >>= 1; solve(); }
    	printf("Collection #%d:\n%s be divided.\n",++ cas, ans ? "Can" : "Can't");
    }
    
    return 0;
}