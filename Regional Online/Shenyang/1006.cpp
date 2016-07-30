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
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;

// Imp
char s[N];

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%s", s);
    	int len = strlen(s);
    	int st = -1, ans = 0;
    	rep(i, len) {
    		if(s[i] == st) { st = i; break; }
    	}
    	if(st == -1) {
    		ans = len / 2 + len % 2;
    	} else {
    		int flag = 0, cnt = 0;
    		for(int i = st, j = 0; j < len; i ++, j ++) {
    			i %= len;
    			if(s[i] == 'c') {
    				if(cnt < 2) {
    					ans = -1;
    					break;
    				} else {
    					ans ++;
    					cnt = 0;
    				}
    			} else {
    				cnt ++;
    			}
    		}
    	}
    	if(len == 0) ans = -1;
    	printf("Case #%d: %d\n", ++ cas, ans);
    }
    
    return 0;
}