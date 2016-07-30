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
#define PII pair<int, int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, ans;
bool vis[1500000];
char x[N], y[N];
struct node{
	int time;
	int df[3], dt[3];
}p[N];
struct cmp{ bool operator()(PII a, PII b) { return a.first > b.first; } };
// Imp
bool bfs() {
	priority_queue<PII, vector<PII>, cmp> que;
	int s = (1 << n) - 1;
	que.push(make_pair(0, s));
	while(!que.empty()) {
		PII u = que.top(); que.pop();
		if(!u.second) {
			ans = u.first;
			return true;
		}
		if(vis[u.second]) continue;
		vis[u.second] = 1;
		rep(i, m) {
			int tmp = u.second, tm = u.first + p[i].time;
			if((tmp & p[i].df[0]) == p[i].df[0] && ((~tmp) & p[i].df[1]) == p[i].df[1]) {
				tmp |= p[i].dt[0], tmp &= (~p[i].dt[1]);
				que.push(make_pair(tm, tmp));
			}
		}
	}
	return false;
}

// #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(sii(n, m), n + m) {
    	mem(vis, 0);
    	rep(i, m) {
    		scanf("%d %s %s", &p[i].time, x, y);
    		p[i].df[0] = p[i].dt[0] = p[i].df[1] = p[i].dt[1] = 0;
    		rep(j, n) {
    			if(x[j] == '+') p[i].df[0] |= (1 << j);
    			else if(x[j] == '-') p[i].df[1] |= (1 << j);
    			if(y[j] == '+') p[i].dt[0] |= (1 << j);
    			else if(y[j] == '-') p[i].dt[1] |= (1 << j);
    		}
    	}
    	printf("Product %d\n", ++ cas);
    	if(bfs()) printf("Fastest sequence takes %d seconds.\n\n", ans);
		else puts("Bugs cannot be fixed.\n");      }
  
    return 0;
}