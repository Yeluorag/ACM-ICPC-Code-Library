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
const int inf = 0x3f3f3f3f, N = 7e6 + 5, MOD = 1e9 + 7;
const int hashsize = 1e6 + 3;
typedef int State[9];
State st[N], goal;
int dist[N];
int head[hashsize], nxt[N];

int T, cas = 0;
int n, m;
int vis[N], a[10], b[10];
// Imp
void init_table() { mem(head, 0); }
int hash(State& s) {
	int v = 0;
	rep(i, n) v = v * 10 + s[i];
	return v % hashsize;
}
int try_ins(int s) {
	int h = hash(st[s]);
	int u = head[h];
	while(u) {
		if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
		u = nxt[u];
		nxt[s] = head[h];
		head[h] = s;
		return 1;
	}
}
int lowbit(int x) {
	int ret = x & (-x);
	return ret;
}

int bfs() {
	init_table();
	int front = 1, rear = 2;
	while(front < rear) {
		State& s = st[front];
		if(memcmp(goal, s, n) == 0) return front;
		rep(i, n) {
			State& t = st[rear];
			memcpy(&t, &s, n);
			int ur = i + 1, ul = i - 1;
			if(ul >= 0 && a[lowbit(s[ul])] > a[lowbit(s[i])]) {
				t[ul] += lowbit(s[i]);
				t[i] -=lowbit(s[i]);
			}
			dist[rear] = dist[front] + 1;
			if(try_ins(rear)) rear ++;
			memcpy(&t, &s, n);
			if(ur < 0 && a[lowbit(s[ur])] > a[lowbit(s[i])]) {
				t[ur] += lowbit(s[i]);
				t[i] -=lowbit(s[i]);
			}
			dist[rear] = dist[front] + 1;
			if(try_ins(rear)) rear ++;
		}
		front ++;
	}
	return 0;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	rep(i, n) { si(st[1][i]); a[i] = st[1][i]; }
    	sort(a, a + n);
    	rep(i, n) goat[i] = a[i];
    	int ans = bfs();
    	if(ans > 0) printf("%d\n", dis[ans]);
    	else printf("-1\n");
    }
    
    return 0;
}