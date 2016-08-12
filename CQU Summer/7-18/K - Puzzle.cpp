// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
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
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
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
int n, m;
string a[5], op;
int sx, sy;
// Imp
bool check(int x, int y) {
	if(x < 0 || x >= 5 || y < 0 || y >= 5) return false;
	return true;
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    while(1) {
    	rep(i, 5) {
    		getline(cin, a[i]);
    		if(!i && a[i] == "Z") return 0;
    		rep(j, 9) if(a[i][j] == ' ') sx = i, sy = j;
    	}
    	if(cas ++) puts("");
    	op.clear();
    	while(1) {
    		string x;
    		getline(cin, x);
    		op += x;
    		if(op[op.size() - 1] == '0') {
    			op.erase(op.size() - 1, 1);
    			break;
    		}
    	}
    	bool ok = 1;
    	rep(i, op.size()) {
    		int nx, ny;
    		if(op[i] == 'A') nx = sx - 1, ny = sy;
    		else if(op[i] == 'B') nx = sx + 1, ny = sy;
    		else if(op[i] == 'L') nx = sx, ny = sy - 1;
    		else nx = sx, ny = sy + 1;
    		if(!check(nx, ny)) {
    			ok = 0;
    			break;
    		}
    		swap(a[sx][sy], a[nx][ny]);
    		sx = nx, sy = ny;
    	}
    	printf("Puzzle #%d:\n", cas);
    	if(!ok) {
    		puts("This puzzle has no final configuration.");
    		continue;
    	}
    	rep(i, 5) rep(j, 5) printf("%c%c", a[i][j], j == 4 ? '\n' : ' ');
    }
    
    return 0;
}