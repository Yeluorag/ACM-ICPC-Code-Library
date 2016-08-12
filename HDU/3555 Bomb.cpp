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
const int inf = 1 << 30;
const int N = 2e1 + 5;

int T, cas = 0;
int a[N];
LL dp[N][3], num, ans;

void init() {
	mem(dp, 0);
	dp[0][0] = 1;
	REP(i, 1, N) {
		dp[i][0] = dp[i-1][0] * 10 - dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1];
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    cin >> T;
    init();
	while(T --) {
		cin >> num;
		mem(a, 0);
		ans = 0;
		int len = 0;
		num ++;
		while(num) {
			a[++len] = num % 10;
			num /= 10;
		}
		int last = -1, flag = 0;
		for(int i = len; i >= 1; i --) {
			ans += dp[i-1][2] * a[i];
			if(flag) ans += dp[i-1][0] * a[i];
			if(!flag && a[i] > 4) ans += dp[i-1][1];
			if(last == 4 && a[i] == 9) flag = 1;
			last = a[i];
		}
		cout << ans << endl;
	}        
    return 0;
}