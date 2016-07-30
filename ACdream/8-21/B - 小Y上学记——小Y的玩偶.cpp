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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, k, tot;
int a[N], vis[N];
int head[N], nxt[N], to[N], va[N];
struct Node{
	int id, v;
}poi[N];
// Imp
void AddEdge(int u, int v, int w) {
	to[tot] = v;
	val[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot ++;
}

void AddEdge(int u, int v) {
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot ++;
}

void DelEdge(int u, int v) {
	for(int i = j = head[u]; i != -1; j = i, i = nxt[i]) {
		if(to[i] == v) {
			if(i == j) head[u] = nxt[i];
			nxt[j] = nxt[i];
			break;
		}
	}
}

int getSum(int u) {
	int ret = 0;
	for(int i = head[u]; i != -1; i = nxt[i]) {
		ret += val[i];
		DelEdge(to[i], u);
	}
	return ret;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n) != EOF) {
    	tot = 0;
    	mem(head, -1);
    	rep(i, n){
    		si(a[i]);
    		poi[i].id = i;
    		poi[i].v = a[i];
    	}
    }
  


    return 0;
}