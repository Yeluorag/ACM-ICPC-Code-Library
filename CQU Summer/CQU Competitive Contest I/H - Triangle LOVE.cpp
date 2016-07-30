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
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, ans, tot;
int a[N][N], tp[N], in[N], head[N*N], nxt[N*N], to[N*N];
// Imp
void AddEdge(int u, int v) {
	to[tot] = v;
	in[v] ++;
	nxt[tot] = head[u];
	head[u] = tot ++;
}

bool topo() {
	int num = 0;
	queue<int>que;
	rep(i, n) if(!in[i]) que.push(i);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		in[u] --;
		tp[num++] = u;
		for(int i = head[u]; i != -1; i = nxt[i])
			if(-- in[i] == 0) que.push(i);
	}
	return num == n;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	ans = 0;
    	tot = 0;
    	mem(in, 0);
    	si(n);
    	rep(i, n) rep(j, n) {
    		si(a[i][j]);
    		AddEdge(i, j);
    	}
    	FOR(i, 0, n - 3) 
    		if(a[tp[i]][tp[i+1]] && a[tp[i+1][tp[i+2]]] && a[tp[i+2]][tp[i]]) 
    			{ ans = 1; break }
    	printf("Case #%d: %s\n", ans ? "Yes" : "No");
    }
     
    return 0;
}