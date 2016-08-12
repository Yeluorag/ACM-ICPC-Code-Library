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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const int M = 3;
int T, cas = 0;
int n, m;
int a[N];
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	si(T);
	while(T --) {
		rep(i, M) si(a[i]);
		sort(a, a + M);
		int t[4] = { -1, -1, -1 };
		printf("Case #%d:\n", ++ cas);
		do {
			int flag = 1;
			rep(i, M) if(t[i] != a[i]) flag = 0;
			if(flag) continue;
			printf("%d %d %d\n", a[0], a[1], a[2]);
			rep(i, M) t[i] = a[i];
		} while(next_permutation(a, a + 3));
	}
    
    
    return 0;
}