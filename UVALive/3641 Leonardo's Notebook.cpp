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
int n, m, vis[N], cnt[N];
char B[N];
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%s", B);
    	mem(vis, 0);
    	mem(cnt, 0);
    	rep(i, 26) {
    		if(!vis[i]) {
    			int j = i, n = 0;
    			do {
    				vis[j] = 1;
    				j = B[j] - 'A';
    				n ++;
    			} while(j != i);
    			cnt[n] ++;
    		}
    	}
    	int ok = 1;
		for(int i = 2; i <= 26; i += 2) if(cnt[i] & 1) ok = 0;
		printf("%s\n", ok ? "Yes" : "No");
    }
    
    return 0;
}