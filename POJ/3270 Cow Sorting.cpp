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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, k;
bool vis[N];
struct node {
	int num, id;
} a[N];
bool cmp(node a, node b) { return a.num < b.num; }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
	    for(int i = 1; i <= n; i ++) si(a[i].num), a[i].id = i;
	    sort(a + 1, a + 1 + n, cmp);
		k = a[1].num;
		mem(vis, 0);
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			int cnt = 0, idx = i, mi = inf, sum = 0;
			while(vis[idx] == 0) {
				vis[idx] = 1;
				cnt ++;
				mi = min(mi, a[idx].num);
				sum += a[idx].num;
				idx = a[idx].id;
			}
			if(sum) ans += min(sum + (cnt - 2) * mi, sum + mi + (cnt + 1) * k);
		}
		printf("%d\n", ans);
	}
    return 0;
}