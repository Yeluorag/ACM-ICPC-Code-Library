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
const int N = 1e1 + 5;
const int MOD = 1e9 + 7;

int dp[N][N], idx;


void init() {
	dp[0][0] = 1;
    for (int i = 1; i <= 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                if (j != 4 && !(j == 3 && k == 7))
                    dp[i][j] += dp[i-1][k];
}

int cal(int n) {
	idx = 0;
	int ret = 0, a[N];
	while(n) {
		a[++idx] = n % 10;
		n /= 10;
	}
	a[idx+1] = 0;
	for(int i = idx; i > 0; i --) {
		rep(j, a[i]) {
			if (j != 4 && !(a[i+1] == 3 && j == 7))
            ret += dp[i][j];
		}
		if(a[i] == 4 || (a[i+1] == 3 && a[i] == 7)) break;
	}
	return ret;
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
    
#endif
    init();
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", cal(b + 1) - cal(a));
    
    return 0;
}