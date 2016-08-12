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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
struct face {
	int x, y;
}a[6];
// Imp
bool judge() {
	if(memcmp(a, a + 1, sizeof(face)) || memcmp(a + 2, a + 3, sizeof(face)) ||
		memcmp(a + 4, a + 5, sizeof(face))) return false;
	if(a[0].x != a[2].x || a[0].y != a[4].x || a[2].y !=a[4].y) return false;
	return true;
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    while(cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y >> a[4].x >> a[4].y >> a[5].x >> a[5].y){  
        for(int i = 0; i < 6; ++i)  
            if(a[i].x < a[i].y)  
                swap(a[i].x, a[i].y);  
        sort(a, a+6,  [](const face a, const face b) {return a.x==b.x ? (a.y > b.y) : (a.x > b.x);});  
        printf("%s\n", judge() ? "POSSIBLE" : "IMPOSSIBLE");  
    }  
    
    return 0;
}