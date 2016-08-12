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

// ------------------------------------------Macro-------------------------------------------
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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// ----------------------------------------Macro End-----------------------------------------

int T, cas = 0;
int n, m, ok, ans;
struct node {
	int time;
	int from[2], to[2];
}patch[N];
struct cmp{
	bool operator()(const PII a, const PII b) {
		return a.first > b.first;
	}
};
int vis[1200000];
priority_queue<PII, vector<PII>, cmp> que;

// --------------------------------------Implementation--------------------------------------

void init() {
	ok = 0;
	while(!que.empty()) que.pop();
	mem(vis, 0);
}

void bfs() {
	int t;
	que.push(make_pair(0, (1 << n) - 1));
	while(!que.empty()) {
		PII u = que.top(); que.pop();
		if(!u.second) {
			ok = 1, ans = u.first;
			return;
		}
		if(vis[u.second]) continue;
		vis[u.second] = 1;
		rep(i, m) {
			t = u.second;
			if(((t) & patch[i].from[0]) == patch[i].from[0] &&
				((~t) & patch[i].from[1]) == patch[i].from[1]) {
					t |= patch[i].to[0];
					t &= (~patch[i].to[1]);
					que.push(make_pair(u.first + patch[i].time, t));
			}
		}
	}
}

void solve() {
	init();
	char fst[N], sec[N];
	rep(i, m) {
		scanf("%d %s %s", &patch[i].time, fst, sec);
		patch[i].from[0] = patch[i].from[1] = patch[i].to[0] = patch[i].to[1] = 0;
		rep(j, n) {
			if(fst[j] == '+') patch[i].from[0] |= (1 << j);
			if(fst[j] == '-') patch[i].from[1] |= (1 << j);
			if(sec[j] == '+') patch[i].to[0] |= (1 << j);
			if(sec[j] == '-') patch[i].to[1] |= (1 << j);
		}
	}
	bfs();
	printf("Product %d\n", ++ cas);
	if(ok) printf("Fastest sequence takes %d seconds.\n\n", ans);
	else puts("Bugs cannot be fixed.\n");  
}


// -----------------------------------------Imp  End-----------------------------------------
//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
// -----------------------------------------Main Pro-----------------------------------------



    // while(~si(n), n) solve();
    while(~sii(n, m), n + m) solve();
    


// ------------------------------------------Pro End-----------------------------------------    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}