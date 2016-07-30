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
const int inf = 0x3f3f3f3f, N = 2e1, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int s[N], p[N], f[1 << N], cover[1 << N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n), n) {
    	int x;
    	int ALL = (1 << n) - 1;
    	for(int i = 0; i < n; i ++) {
    		si(m);
    		p[i] = 1 << i;
    		for(int j = 0; j < m; j ++) {
    			si(x);
    			p[i] |= 1 << x;
    		}
    	}

    	for(int S = 0; S < (1 << n); S ++) {
    		cover[S] = 0;
    		for(int i = 0; i < n; i ++)
    			if(S & (1 << i)) cover[S] |= p[i];
    	}

    	mem(f, 0);
    	for(int S = 1; S <= ALL; S ++) for(int S0 = S; S0; S0 = (S0 - 1) & S)
    		if(cover[S0] == ALL) f[S] = max(f[S], f[S ^ S0] + 1);

    	printf("Case %d: %d\n", ++ cas, f[ALL]);
    }
    
    return 0;
}