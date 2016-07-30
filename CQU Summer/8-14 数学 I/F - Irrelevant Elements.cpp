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
int n, m;
int p[105], e[105], pn;
VI ans;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(~sii(n, m)) {
    	pn = 0;
    	ans.clear();
    	int k = (int)sqrt(m + 0.5);
    	FOR(i, 2, k) {
    		if(m % i == 0) {
    			p[pn] = i, e[pn] = 0;
    			while(m % i == 0) m /= i, e[pn] ++;
    			pn ++;
    		}
    		if(m == 1) break;
    	}
    	if(m > 1) p[pn] = m, e[pn] = 1, pn ++;
    	int cnt = pn;
    	REP(i, 1, n) {
    		int a = n - i, b = i;
    		rep(j, pn) {
    			while(a % p[j] == 0) {
    				a /= p[j];
    				e[j] --;
    				if(!e[j]) cnt --;
    			}
    			while(b % p[j] == 0) {
    				b /= p[j];
    				e[j] ++;
    				if(e[j] == 1) cnt ++;
    			}
    		}
    		if(!cnt) ans.pb(i + 1);
    	}
    	put(ans.size());
    	if(ans.empty()) ET;
    	rep(i, ans.size()) printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}