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
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int tow[10][10];
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(T);
    while(T --) {
    	for(int i = 0; i < 9; i += 2) 
    		for(int j = i; j < 9; j += 2)
    			si(tow[i][j]);
    	for(int i = 8; i > 1; i --) {
    		rep(j, 7) {
    			int &x = tow[i-1][j], &y = tow[i-1][j+1], &z = tow[i][j+1];
    			int &a = tow[i-2][j], &b = tow[i][j], 	  &c = tow[i][j+2];
    			z = (a - b - c) / 2;
    			x = b + z;
    			y = c + z;
    		}
    	}
    	rep(i, 9) {
    		rep(j, i + 1) printf("%d ", tow[i][j]); 
    		ET;
    	} 
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}