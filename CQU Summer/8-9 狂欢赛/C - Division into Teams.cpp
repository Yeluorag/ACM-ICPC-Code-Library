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

int n, x = 0, y = 0, mx = -1, sum = 0, ret = 0, flag[N];
struct node{
	int s, id;
}a[N];
bool cmp(node p, node q) { return p.s > q.s; }
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(n);
    mem(flag, 0);
    FOR(i, 1, n) { si(a[i].s); a[i].id = i; mx = max(mx, a[i].s); sum += a[i].s; }
    sort(a + 1, a + n + 1, cmp);
    int cnt = n / 2;
    for(int i = 1; i <= n; i += 2) {
    	ret += a[i].s;
    	x ++;
    }
    printf("%d\n", x);
    for(int i = 1; i <= n; i += 2) printf("%d ", a[i].id); ET;
    printf("%d\n", n - x);
	for(int i = 2; i <= n; i += 2) printf("%d ", a[i].id); ET;
    return 0;
}