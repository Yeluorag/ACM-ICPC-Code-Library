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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
const int inf = 0x3f3f3f3f, N = 16, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N][N][N][N][N], cnt[N][N][N][N] t[N];
int up[13], left[13], down[13], right[13];

int hu[] = { 2, 5, 6, 8, 9, 10, 12 };
int hl[] = { 3, 4, 5, 8, 9, 11, 12 };
int hd[] = { 2, 5, 6, 8, 9, 10, 12 };
int hr[] = { 3, 4, 5, 8, 9, 11, 12 };
// Imp
void init() {
	mem(up, 0); mem(left, 0);
	rep(i, 7) up[hu[i]] = left[hl[i]] = down[hd[i]] = right[hr[i]] = 1;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	

    sii(n, m);
    FOR(i, 1, 12) si(t[i]);
    mem(dp, 0);
    FOR(i, 1, 12) if(t[i] > 0) dp[1][1][i][1] = 1;
    FOR(x, 1, n) {
    	FOR(y, 1, m) {
    		FOR(i, 1, 12) {  //当前12个种砖第i种
    			FOR(j, 1, t[i]) {	// 第i种的第j个
    				FOR(k, 1, 12) { //上一状态12个种砖第k种
    					if(down[k]){
	    					if(up[i] && x > 1) {
	    						FOR(p, 1, 12) {
    								FOR(q, 1, t[p]) {
    									dp[x][y][i][j][p][q] = dp[x-1][y][k][j-1];
    								}
    							}

	    						if(k == i && j > 1) {

	    						}
	    						else {
	    							FOR(l, 1, t[k]) {	//上一状态第k种第l个
	    								dp[x][y][i][k] += dp[x-1][y][k][l];
	    							}
	    						}
	    					}
    					}
    					if(right[k]) {
	    					if(left[i] && y > 1) {
	    						if(k == j && j > 1) dp[x][y][i][j] += dp[x][y-1][k][j-1];
	    						else {
	    							FOR(l, 1, t[k]) {
	    								dp[x][y][i][k] += dp[x][y-1][k][l];
	    							}
	    						}
	    					}
    					}
    				}
    			}
    		}
    	}
    }
    
    return 0;
}