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
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
LL ans[N];
void init() {
	mem(ans, 0);
	for(int i = 4; i < N; i ++) {
		int k = i / 2 - 1;
		ans[i] = ans[i-1] + (LL)(i % 2 + i - 2) * (LL)k / 2;
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

	init();
    while(si(n) != EOF) {
    	if(n < 3) break;
    	printf("%lld\n", ans[n]);
    } 
    return 0;
}