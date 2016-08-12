// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, a[N];
int ls[N], rs[N];

// Imp
void print(int par) {
	if(par != a[0]) printf(" ");
	printf("%d", par);
	if(ls[par] != -1) print(ls[par]);
	if(rs[par] != -1) print(rs[par]);
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	mem(ls, -1), mem(rs, -1);
    	si(a[0]);
    	int rt = a[0];
    	REP(i, 1, n) {
    		si(a[i]);
    		int t = rt;
    		rep(j, N) {
    			if(a[i] < t) {
    				if(ls[t] == -1) {
    					ls[t] = a[i];
    					break;
    				}
    				t = ls[t];
    			}
    			else {
    				if(rs[t] == -1) {
    					rs[t] = a[i];
    					break;
    				}
    				t = rs[t];
    			}
    		}
    	}
    	print(a[0]);
    	puts("");
    }
    
    return 0;
}