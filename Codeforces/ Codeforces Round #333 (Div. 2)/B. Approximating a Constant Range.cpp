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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, M = 1e5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N], last[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(n);
    for(int i = 0; i < n; i ++) si(a[i]);
    mem(last, -1);
    int ans = 0, l = 0;
	for(int i = 0; i < n; i ++) {
		int x = -1;
		if(a[i] + 2 <= M) x = max(x, last[a[i] + 2] + 1);
		if(a[i] - 2 >= 0) x = max(x, last[a[i] - 2] + 1);
		l = max(l, x);
		ans = max(ans, i - l + 1);
		last[a[i]] = i;
	}
    printf("%d\n", ans);

    return 0;
}