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
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 31, N = 1e5 + 5, MOD = 1e9 + 7;

int n, x[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    cin >> n;
    rep(i, n) scanf("%d", &x[i]);
    rep(i, n) {
    	int mi, mx;
    	if(i == 0) {
    		mi = x[1] - x[0];
    		mx = x[n-1] - x[0];
    	} else if(i == n - 1) {
    		mi = x[n-1] - x[n-2];
    		mx = x[n-1] - x[0];
    	} else {
    		mi = min(x[i] - x[i-1], x[i+1] - x[i]);
    		mx = max(x[i] - x[0], x[n-1] - x[i]);
    	}
    	printf("%d %d\n", mi, mx);
    }
    return 0;
}