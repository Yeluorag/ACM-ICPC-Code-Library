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
const int inf = 1 << 30, N = 1e3 + 5, MOD = 1e9 + 7;

int n, ans, a[N], sum[10005];
map<int, int> mp;
VI st;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n) != EOF) {
    	mem(sum, 0);
    	ans = -1;
    	st.clear();
    	mp.clear();
    	rep(i, n) {
    		si(a[i]);
    		if(!mp[a[i]]) {
    			mp[a[i]] = 1;
    			st.pb(a[i]);
    		}
    		sum[a[i]] += 1;
    	}
    	int len = st.size();
    	rep(i, len) if(sum[st[i]] * 2 > n) ans = st[i];
    	printf("%d\n", ans);
    }
    
    return 0;
}