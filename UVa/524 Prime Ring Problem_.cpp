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
const int inf = 0x3f3f3f3f, N = 20 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int A[N], isp[105], vis[N];
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

void dfs(int cur) {
	if(cur == n) {
		if(!isp[A[n - 1] + 1]) return;
		for(int i = 0; i < n - 1; i ++) printf("%d ",  A[i]);
		printf("%d\n", A[n - 1]);
		return;
	}
	for(int i = 2; i <= n; i ++) {
		if(isp[i + A[cur - 1]] && !vis[i]) {
			vis[i] = 1;
			A[cur] = i;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	mem(isp, 0);
	for(int i = 0; i < 11; i ++) isp[prime[i]] = 1;
	A[0] = 1;
    while(si(n) != EOF) {
    	mem(vis, 0); vis[1] = 1;
    	if(cas ++) puts("");
    	printf("Case %d:\n", cas);
    	dfs(1);
    	
    }
    
    return 0;
}