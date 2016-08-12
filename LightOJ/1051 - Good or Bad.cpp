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
const int inf = 0x3f3f3f3f, N = 50 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp1[N][4], dp2[N][6], a[N];
char s[N];
char print[][N] = { "MIXED", "GOOD", "BAD" };
int judge(char x)  {  
    return x == 'A' || x=='E' || x=='I' || x=='O' || x == 'U';  
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%s", s + 1);
    	mem(a, 0);
    	n = strlen(s + 1);
    	mem(dp1, 0), mem(dp2, 0);
    	dp1[0][0] = dp2[0][0] = 1;
    	for(int i = 1; i <= n; i ++) {
    		if(s[i] == '?') a[i] = 0;
    		else if(judge(s[i])) a[i] = 1;
    		else a[i] = 2;

    		for(int j = 0; j <= 2; j ++) {
    			if(dp1[i-1][j]) {
    				if(a[i] == 0 || a[i] == 2) dp2[i][1] = 1; 
    				if(a[i] == 0 || a[i] == 1) dp1[i][j+1] = 1;
    			}
    		}
    		for(int j = 0; j <= 4; j ++) {
    			if(dp2[i-1][j]) {
    				if(a[i] == 0 || a[i] == 2) dp2[i][j+1] = 1; 
    				if(a[i] == 0 || a[i] == 1) dp1[i][1] = 1;
       			}
    		}
    	}
    	int good = 0, bad = 0, ans;
    	for(int i = 0; i <= 2; i ++) good |= dp1[n][i];
    	for(int i = 0; i <= 4; i ++) good |= dp2[n][i];
    	for(int i = 1; i <= n; i ++) if(dp1[i][3] || dp2[i][5]) bad = 1;
    	if(good && bad) ans = 0;
    	else if(good) ans = 1;
    	else ans = 2;

    	printf("Case %d: %s\n", ++ cas, print[ans]);
    }
    
    return 0;
}