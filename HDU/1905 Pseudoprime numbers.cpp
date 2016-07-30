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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int a, p;
// Imp
bool judge(int n) {
	int m = sqrt(n + 0.5);
	if(n == 1) return true;
	FOR(i, 2, m) if(n % i == 0) return true;
	return false;
}
LL Pow(LL a, LL t) {
	if(t == 0) return 1;
	LL x = Pow(a, t / 2);
	LL ans = x * x % p;
	if(t & 1) ans = ans * a % p;
	return ans;
}

int main(){
#ifdef LOCAL
    IN;
//  OUT;
#endif
	
    while(cin >> p >> a, a + p) {
    	LL k = Pow(a, p);
    	if(k % p == a && judge(p)) puts("yes");
    	else puts("no");
    }
    
    return 0;
}