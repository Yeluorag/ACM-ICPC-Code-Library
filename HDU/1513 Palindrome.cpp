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
const int inf = 0x3f3f3f3f, N = 5e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
string s1, s2;
int dp[2][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
	    cin >> s1;
	    s2.assign(s1.rbegin(), s1.rend());
	    mem(dp, 0);
	    for(int i = 0; i < n; i ++) {
	    	for(int j = 0; j < n; j ++) {
	    		if(s1[i] == s2[j]) dp[(i + 1) & 1][j + 1]= dp[i & 1][j] + 1;
	    		else dp[(i + 1) & 1][j + 1] = max(dp[i & 1][j + 1], dp[(i + 1) & 1][j]);
	    	}
	    }
	    
	    printf("%d\n", n - dp[n & 1][n]);
	}
    return 0;
}