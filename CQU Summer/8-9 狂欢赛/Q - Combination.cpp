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
const int inf = 1 << 30, N = 1e3 + 5, MOD = 1e9 + 7;

int n, cnt = 1, ans = 0;
struct node{
	int a, b;
}c[N];

queue<node> que;
bool cmp(node p, node q) {
	if(p.b == q.b) return p.a > q.a;
	return p.b > q.b;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(n);
    rep(i, n) sii(c[i].a, c[i].b);
    sort(c, c + n, cmp);
    rep(i, n) que.push(c[i]);
    while(!que.empty()) {
    	if(cnt <= 0) break;
    	cnt --;
    	node nxt = que.front(); que.pop();
    	cnt += nxt.b;
    	ans += nxt.a;
    }
    printf("%d\n", ans);
    return 0;
}