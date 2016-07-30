#define LOCAL
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
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
const int inf = 1 << 30, N = 1e1 + 1, MOD = 1e9 + 7;

int n;
LL bit[N], dp[N][N][2][N], a[N];

void init() {
	mem(dp, 0);
	dp[0][0][0][0] = 1;
	bit[0] = 1;
	REP(i, 1, N) bit[i] = bit[i-1] * 10; 
	rep(x, 10) {
		rep(i, 11) {
			rep(j, 10) {
				rep(k, 2){
					if(k) {
						dp[i][j][k][l] = dp[i-1][x][1][(l - j * bit[i-1]) % 13];
 						if(j == 1 && x == 3) dp[i][j][k][l] += dp[i-1][x][0][(l - j * bit[i-1]) % 13];
					} else {
						if(!(j == 1 && x == 3)) dp[i][j][k][l] = dp[i-1][x][0][(l - j * bit[i-1]) % 13];
					}
				}
			}
		}
	}
}

int cal(int x) {
	int len = 0;
	while(x) {
		a[++len] = x % 10;
		x /= 10;
	}
	a[len+1] = 0;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    init();
    while(scanf("%d", &n) != EOF) {

    }
    
    return 0;
}