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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int R, B;
double dp[N][N];

void init() {
	mem(dp, 0);
	dp[0][0] = 1.0;
	for(int i = 1; i <= 500; i ++) {
		dp[i][0] = 0.0;
		dp[0][i] = 1.0;
	}
	for(int i = 1; i <= 500; i ++) {
		for(int j = 1; j <= 500; j ++) {
			if(i > j) dp[i][j] = 0.0;
			else {
				dp[i][j] = dp[i-1][j-1] * i * 1.0 / (i + j);
				if(j - 2 >= 0) dp[i][j] += dp[i][j-2] * j * 1.0 / (i + j);
			}
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	init();
    si(T);
    while(T --) {
    	sii(R, B);
    	printf("Case %d: %.10f\n", ++ cas, dp[R][B]);
    }
    	
    return 0;
}