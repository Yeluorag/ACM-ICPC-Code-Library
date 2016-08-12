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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct Word {
	int len;
	char s[21];
} word[N];
struct Edge {
	int st, ed;
	bool del;
} edge[N];
int in[30], out[30];
int stk[N], fa[N];
bool vis[30];
int E, top;

int cmp(const void* a, const void* b) {
	 return strcmp( ((Word*)a)->s, ((Word*)b)->s );  
}
int find(int x) {
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
bool judge() {
	int t = 0;
	for(int i = 0; i < 26; i ++) {
		if(vis[i] && fa[i] == i) t ++;
	}
	return t == 1;
}

void euler(int u) {
	for(int i = 0; i < E; ++ i) {
		if(!edge[i].del && edge[i].st == u) {
			edge[i].del = true;
			euler(edge[i].ed);
			stk[top ++] = i;
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(E);
    	int u, v, c1, c2, start;
    	for(int i = 0; i < 26; ++ i) {
    		in[i] = out[i] = 0;
    		fa[i] = i;
    		vis[i] = false;
       	}
       	for(int i = 0; i < E; ++ i) {
       		scanf("%s", word[i].s);
       		word[i].len = strlen(word[i].s);
       	}

       	// sort(word, word + E, cmp);
		qsort(word, E, sizeof(word[0]), cmp);

		for(int i = 0; i < E; ++ i) {
			u = word[i].s[0] - 'a';
			v = word[i].s[word[i].len - 1]  - 'a';
			edge[i].st = u, edge[i].ed = v;
			edge[i].del = false;
			vis[u] = vis[v] = true;
			++ in[v]; ++ out[u];
			u = find(u);
			v = find(v);
			if(u != v) fa[v] = u;
		}       	

		c1 = c2 = 0;
		start = edge[0].st;
		int i;
    	for(i = 0; i < 26; ++ i) {
    		if(in[i] == out[i]) continue;
    		else if(in[i] - 1 == out[i]) ++ c1;
    		else if(out[i] - 1 == in[i]) { ++ c2; start = i; }
    		else break;
    	}

    	if(i == 26 && ((c1 == c2 && c1 == 1) || (c1 == c2 && c1 == 0)) && judge()) {
    		top = 0;
    		euler(start);
    		for(i = top - 1; i > 0; -- i) printf("%s.", word[stk[i]].s);
    		printf("%s\n", word[stk[0]].s);
    	} else puts("***");

    }
    
    return 0;
}