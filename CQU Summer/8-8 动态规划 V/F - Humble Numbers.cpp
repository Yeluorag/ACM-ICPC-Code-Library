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
const int inf = 2e9, N = 5843, MOD = 1e9 + 7;

int n, dp[N];
char s[5][5] = { "st", "nd", "rd" };

void init() {
	int idx = 1; dp[1] = 1;
	int a, b, c, d;
	a = b = c = d = 1;
	while(dp[idx] < inf) {
		dp[++idx] = min(min(2 * dp[a], 3 * dp[b]), min(5 * dp[c], 7 * dp[d]));
		if(dp[idx] == 2 * dp[a]) a++;  
        if(dp[idx] == 3 * dp[b]) b++;
        if(dp[idx] == 5 * dp[c]) c++; 
        if(dp[idx] == 7 * dp[d]) d++; 
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    init();
	while(si(n), n) {
		int idx = (n - 1 ) % 10;
		printf("The %d", n);
		if(n%10 == 1&&n%100!=11) printf("st");  
        else if(n%10 == 2&&n%100!=12) printf("nd");  
        else if(n%10 == 3&&n%100!=13) printf("rd");  
        else printf("th");  
		printf(" humble number is %d.\n", dp[n]);
	}    
    
    return 0;
}