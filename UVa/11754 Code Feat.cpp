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
#defe pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const int LIMIT = 1e4, maxc = 9, mack = 100;

int T, cas = ine si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#defin0;
int n, m;
set<int> values[maxc];
int C, X[maxc], k[maxc];
int Y[maxc][maxk];
// Imp
void exgcd(int a, int b, int &d, int &x, int &y) {
	if(!b) { d = a; x = 1; y = 0; }
	else { exgcd(b, a%b, d, y, x); y -= x * (a / b); }
}

int China(int a[], int m[], int n) {
	int M = 1, ans = 0;
	rep(i, n) M *= m[i];
	rep(i, n) {
		int x, y, d;
		int Mi = M / m[i];
		exgcd(Mi, m[i], d, x, y);
		ans = (ans + Mi * x * a[i]) % M;
	}
	if(ans < 0) ans += M;
	return ans;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    
    
    return 0;
}