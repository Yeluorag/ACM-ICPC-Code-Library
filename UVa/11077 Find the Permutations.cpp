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
const int inf = 0x3f3f3f3f, N = 3e1 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
unsigned long long f[N][N];

// Imp


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    mem(f, 0);
    f[1][0] = 1;
    FOR(i, 2, 21)  rep(j, i) {
		f[i][j] = f[i - 1][j];
		if(j > 0) f[i][j] += f[i - 1][j - 1] * (i - 1);
	}
    while(sii(n, m), n + m) printf("%llu\n", f[n][m]);
    
    return 0;
}