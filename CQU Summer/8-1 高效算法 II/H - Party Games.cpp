// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
string s[N];
// Imp


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n), n) {
    	FOR(i, 1, n) cin >> s[i];
    	sort(s + 1, s + 1 + n);
    	string &u = s[n >> 1], &v = s[(n >> 1) + 1];
    	string ans, tmp;
    	int cur = 0, ok = 0;
    	while(1) {
    		rep(i, 26) {
    			tmp = ans;
    			tmp.pb('A' + i);
    			if(tmp >= u && tmp < v) {
    				ans = tmp;
    				ok = 1;
    				break;
    			}
    		}
    		if(ok) break;
    		ans.pb(u[cur++]);
    	}
    	cout << ans <<endl;
    }  	

    return 0;
}
