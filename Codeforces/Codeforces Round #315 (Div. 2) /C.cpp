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

int pi[N], rub[N], p, q, A, ans = 0;
int prim[N], par[N];

bool isPar(int t) {
	char s[10];
	int idx = 0;
	while(t) {
		s[idx++] = t % 10;
		t /= 10;
	}
	for(int j = 0; j < idx / 2; j ++) if(s[j] != s[idx-j-1]) return false;
	return true;
}

bool isPrim(int t) {
	if(t < 2) return false;
	for(int j = 2; j * j <= t; j ++)
			if(t % j == 0) return false;
	return true;
}

void init() {
	pi[1] = 0; rub[0] = 1;
	for(int i = 1; i < N; i ++) {
		rub[i] = rub[i-1]; pi[i] = pi[i-1];
		if(isPar(i)) rub[i] ++;
		if(isPrim(i)) pi[i] ++;
	}
}

bool check(int t) {
	return p * rub[t] >= q * pi[t];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    sii(p, q);
    init();
    rep(i, N) {
    	if(check(i)) ans = i;
    	else break;
    }
    printf("%d\n", ans);
    return 0;
}