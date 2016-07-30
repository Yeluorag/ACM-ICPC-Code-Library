// Header.
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

int T, cas = 0;
int n, m, q;
int t[3 * N], a[N], ask[N];
// Imp
void print(int x, int now) {
	if(x > a[now]) {
		printf("W");
		print(x, now * 2 + 1);
	} else {
		printf("E");
		print(x, now * 2 + 2);
	}
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	mem(t, -1);
    	si(n);
    	si(a[0]);
    	t[0] = a[0];
    	REP(i, 1, n) {
    		si(a[i]);
    		int lf = 0;
    		while(1) {
    			int lt;
    			if(a[i] > t[lf]) lt = 2 * lf + 1;
    			else lt = 2 * lf + 2; 
    			if(t[lt] == -1) {
					t[lt] = a[i];
					break;
				} else lf = lt;
    		}
    	}
    	rep(i, n) si(ask[i]);
    	rep(i, n) {
    		if(ask[i] == t[0]) puts("");
    		else print(ask[i], 0);
    	}

    }
    
    return 0;
}