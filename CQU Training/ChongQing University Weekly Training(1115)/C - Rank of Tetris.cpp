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
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, cnt;
int fa[N], in[N], x[2 * N], y[2 * N];
char c[2 * N];
vector<int> v[N];

int find(int x) {
	if(x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

bool Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx == fy) return false;
	fa[fx] = fy;
	return true;
}

int Topo() {
	queue<int> que;
	rep(i, n) if(in[i] == 0 && find(i) == i) que.push(i);
	int ret = 0;
	while(!que.empty()) {
		if(que.size() > 1) ret = 1;
		int u = que.front(); que.pop();
		cnt ++;
		int len = v[u].size();
		rep(i, len) if(-- in[v[u][i]] == 0) que.push(v[u][i]);
	}
	if(cnt < n) return 0;
	else if(ret) return -1;
	return 1;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	cnt = 0;
		mem(in, 0);
		rep(i, n) fa[i] = i, v[i].clear();
		rep(i, m) {
			scanf("%d %c %d", &x[i], &c[i], &y[i]);
			if(c[i] == '=') if(Union(x[i], y[i])) cnt ++;
		}
		rep(i, m) {
			int fx = find(x[i]), fy = find(y[i]);
			if(c[i] == '>') v[fx].pb(fy), in[fy] ++;
			if(c[i] == '<') v[fy].pb(fx), in[fx] ++;
		}
		int ans = Topo();
		if(ans == 1) printf("OK\n");
		if(ans == 0) printf("CONFLICT\n");
		if(ans == -1) printf("UNCERTAIN\n");
    }
    
    return 0;
}