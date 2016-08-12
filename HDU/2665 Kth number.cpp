// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;

struct ChairTree {
    const static int maxn = 1e5 + 5;
    #define x first
    #define y second
    struct node {
        int l, r, size;
    } T[maxn * 25];     //nlogn
    int sz, root[maxn], rank[maxn];
    pair<int, int> a[maxn];
    void insert(int& i, int l, int r, int x) {
        int m = (l + r) >> 1;
        T[++sz] = T[i]; i = sz;
        T[i].size ++;
        if(l == r) return;
        if(x <= m) insert(T[i].l, l, m, x); else insert(T[i].r, m + 1, r, x);
    }
    int find(int x, int y, int k) {
        int l = 1, r = n;
        x = root[x-1], y = root[y];
        while(l != r) {
            int m = (l + r) >> 1, t = T[T[y].l].size - T[T[x].l].size;
            if(k <= t) x = T[x].l, y = T[y].l, r = m;
            else x = T[x].r, y = T[y].r, l = m + 1, k -= t;
        }
        return a[l].x;
    }
    void init() {
        root[0] = sz = 0;
        FOR(i, 1, n) si(a[i].x), a[i].y = i;
        sort(a + 1, a + n + 1);
        FOR(i, 1, n) rank[a[i].y] = i;
        FOR(i, 1, n) insert(root[i] = root[i-1], 1, n, rank[i]);
    }
} Tree;
// Imp
void solve() {
	int l, r, k;
	Tree.init();
	while(m --) {
		siii(l, r, k);
		put(Tree.find(l, r, k));
	}
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	solve();
    }
    
    return 0;
}