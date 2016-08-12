#define LOCAL
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
const int inf = 1 << 30, N = 1e5 + 5, MOD = 1e9 + 7;

int n, ans, ret1, ret2, ret3, ret4, vis[25];
struct node{
	int x, y;
}a[25], t[10];

bool cmp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int dis(node a, node b) { return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x); }

void dfs1(int cur) {
	if(cur == 3) {
		int b = dis(t[0], t[1]), c = dis(t[1], t[2]), d = dis(t[0], t[2]);
		if(d == b && b == c) ret1 ++;
	}
	rep(i, n) {
		if(!vis[i]) {
			t[cur].x = a[i].x;
			t[cur].y = a[i].y;
			vis[i] = 1;
			dfs1(cur + 1);
			vis[i] = 0;
		}
	}
}

void dfs2(int cur) {
	if(cur == 4) {
		sort(t, t + 4, cmp);
		int b = dis(t[0], t[1]), c = dis(t[1], t[2]), d = dis(t[2], t[3]), e = dis(t[3], t[0]);
		if(b == c && c == d && d == e) ret2 ++;
	}
	rep(i, n) {
		if(!vis[i]) {
			t[cur].x = a[i].x;
			t[cur].y = a[i].y;
			vis[i] = 1;
			dfs2(cur + 1);
			vis[i] = 0;
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n) != EOF) {
    	rep(i, n) sii(a[i].x, a[i].y);
    	ans = 0;
    }
    
    return 0;
}