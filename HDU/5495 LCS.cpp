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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N], b[N], vis[N], hs[20 * N];
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	mem(vis, 0);
    	si(n);
    	rep(i, n) si(a[i]), hs[a[i]] = i;
    	rep(i, n) si(b[i]);
    	int num = 0;
    	rep(i, n) {
    		if(!vis[i]) {
    			int id = i, cnt = 0;
    			do {
    				vis[id] = 1;
    				cnt ++;
    				id = hs[b[id]];
    			} while(id != i);
    			num += cnt > 1;
    		}
    	}
    	printf("%d\n", n - num);
    }
    
    return 0;
}