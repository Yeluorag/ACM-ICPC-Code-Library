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
const int inf = 0x3f3f3f3f, N = 4e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int v[N], d[N], p[N], vis[N], dol;
vector<int> ans;
void update(int i) {
	if(p[i] < 0) {
		if(!vis[i]) dol += d[i];
        vis[i] = 1;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(n);
    ans.clear();
    mem(vis, 0);
    FOR(i, 1, n) siii(v[i], d[i], p[i]);
    
    FOR(i, 1, n) {
        if(p[i] >= 0) {
        	ans.pb(i);
        	int vol = v[i];
        	dol = 0;
        	FOR(j, i + 1, n) {
        		if(vol > 0) {
        			if(p[j] >= 0) {
        				p[j] -= vol;
        				vol --;
        			}
        		}
        		update(j);
        		p[j] -= dol;
        		update(j);
        	}
        }
    }
    sort(ALL(ans));
    int sz = ans.size();
    printf("%d\n", sz);
    rep(i, sz - 1) printf("%d ", ans[i]);
    printf("%d\n", ans[sz - 1]);
    return 0;
}