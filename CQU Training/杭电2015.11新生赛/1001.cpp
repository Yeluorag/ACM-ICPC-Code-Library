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
const int inf = 0x3f3f3f3f, N = 1e7 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, dp[N];

void init() {
	dp[1] = 0;
	for(int i = 2; i < N ; i ++) {
		if(i & 1) dp[i] = dp[i/2] + dp[i/2 + 1] + 1;
		else dp[i] = 2 * dp[i/2];
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
    	si(n);
    	printf("%d\n", dp[n]);
    }
    
    return 0;
}