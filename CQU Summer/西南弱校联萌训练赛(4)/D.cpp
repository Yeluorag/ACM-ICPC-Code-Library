// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
#define PII pair<int, int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, k, t, q;
map<int, map<int, int> > mp;
map<int, int> row, col;
// Imp

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    si(T);
    while(T --) {
    	row.clear();
    	col.clear();
    	mp.clear();
    	siii(n, m, k);
    	int a, b, c;
    	int ur = 1, uc = 1;
    	rep(i, k) {
    		siii(a, b, c);
    		if(!row[a]) row[a] = ur ++;
    		if(!col[b]) col[b] = uc ++;
    		mp[row[a]][col[b]] = c;
    	}
    	si(t);
    	printf("Case #%d:\n", ++ cas);
    	while(t --) {
    		siii(q, a, b);
    		if(q == 1) swap(row[a], row[b]);
    		else if(q == 2) swap(col[a], col[b]);
    		else printf("%d\n", mp[row[a]][col[b]]);
    	}
    }
    
    return 0;
}