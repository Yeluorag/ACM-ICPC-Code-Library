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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char s[N];
int dp[N][N];
bool check(int i, int j) {
	return (s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']');
}

int dfs(int l, int r) {
	int& ret = dp[l][r];
	if(ret != -1) return ret;
	if(l >= r) return ret = 0;
	if(r == l + 1) return ret = check(l, r) ? 2 : 0;
	ret = dfs(l + 1, r);
	for(int m = l + 1; m <= r; m ++)
		if(check(l, m)) ret = max(ret, 2 + dfs(l + 1, m - 1) + dfs(m + 1, r));
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%s", s) != EOF) {
    	if(s[0] == 'e') break;
    	mem(dp, -1);
    	int len = strlen(s);
    	printf("%d\n", dfs(0, len - 1));
    }
    
    return 0;
}