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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n;
int vis[N], ans[N];
struct node {
    int i, val, id;
    bool operator < (const node & rhs) const {
    	return val < rhs.val;
    }
};
// Imp
bool cmp(node p, node q) { return p.val > q.val; }


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    priority_queue<node> que;
    si(n); n <<= 1;
    FOR(i, 2, n) {
        REP(j, 1, i) {
            int t;
            si(t);
            que.push((node){i, t, j});
        }
    }
    mem(vis, 0);
    while(!que.empty()) {
    	node tmp = que.top(); que.pop();
    	if(vis[tmp.i] || vis[tmp.id]) continue;
    	ans[tmp.i] = tmp.id;
    	ans[tmp.id] = tmp.i;
    	vis[tmp.id] = vis[tmp.i] = 1;
    }
    REP(i, 1, n) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}