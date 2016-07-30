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
int a[N], ans;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	for(int i = 0; i < n; ++ i) si(a[i]);
    	set<int> s;
    	ans = 0;
    	int R = 0, L = 0, len = 1;
    	while(R < n) {
    		while(R < n && !s.count(a[R])) s.insert(a[R ++]);
    		ans = max(ans, R - L);
    		s.erase(a[L ++]);
    	}
    	printf("%d\n", ans);
    }
    
    return 0;
}