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
const int inf = 0x3f3f3f3f, N = 2e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[20][N];
int bit[20];
int A, B;
int dfs(int pos, int num, bool flag) {
	if(pos == -1) return num >= 0;
	if(num < 0) return 0;
	if(!flag && dp[pos][num] != -1) return dp[pos][num];
	int ret = 0;
	int ed = flag ? bit[pos] : 9;
	for(int i = 0; i <= ed; i ++)
		ret += dfs(pos - 1, num - i * (1 << pos), flag && i == ed);
	if(!flag) dp[pos][num] = ret;
	return ret;
}

int F(int x) {
	int ret = 0, len = 0;
	while(x) {
		ret += (x % 10) * (1 << len);
		len ++;
		x /= 10;
	}
	return ret;
}

int cal() {
	int len = 0;
	while(B) {
		bit[len++] = B % 10;
		B /= 10;
	}
	return dfs(len - 1, F(A), true);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	mem(dp, -1);
	si(T);
	while(T --) {
		sii(A, B);
		printf("Case #%d: %d\n", ++ cas, cal());
	}
    
    
    return 0;
}