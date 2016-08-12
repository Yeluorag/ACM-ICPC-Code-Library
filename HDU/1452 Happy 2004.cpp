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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 29;
// Macro end

int T, cas = 0;
int n, m;
// Imp
int Pow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = (ret * a) % MOD;
		a = (a * 2) % MOD;
		b >>= 1;
	}
	return ret % MOD;
}

int main(){
#ifdef LOCAL 
    IN // OUT
#endif
	
    while(si(n) != EOF, n) {
    	int a = Pow(2, 2 * n + 1) - 1,
    		b = Pow(3, n + 1) - 1,
    		c = Pow(22, n + 1) - 1;
    	int t = a * b * c * 15 * 18;
    	cout << a * b * c * 15 * 18 % MOD << endl;
    }
    
    return 0;
}