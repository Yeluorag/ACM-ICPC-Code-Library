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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
bool vis[N];
vector<int>primes;
void Init_Primes() {
	mem(vis, 0);
	int m = sqrt(N + 0.5);
	FOR(i, 2, m) if(!vis[i])
		for(int j = i * i; j < N; j += i) vis[j] = 1; 
	REP(i, 2, N) if(!vis[i])
	primes.pb(i);
}
int has[N], fac[N][7], facn[N];
void getfactor() {
	REP(i, 2, N) {
		int n = i, cnt = 0;
		int sz = primes.size();
		rep(j, sz) {
			if(!vis[n]) {
				fac[i][cnt++] = n;
				break;
			}
			if(n % primes[j] == 0) {
				fac[i][cnt++] = primes[j];
				while(n % primes[j] == 0) n/= primes[j];
			}
		}
		facn[i] = cnt;
	}
}
int a[N], cntExtend[N];
void factorExtend(int len) {
	mem(cntExtend, 0);
	REP(i, 1, N) {
		for(int j = i; j < N; j += i) {
			if(has[j]) cntExtend[i] ++;
		}
	}
}

LL solve(int len) { 
	LL ret = 0;
	rep(i, len) {
		int n = a[i];
		if(n == 1) continue;
		int facnum = facn[n];
		LL sum = 0;
		for(int k = (1 << facnum) - 1; k > 0; k --) {
			int mul = 1, b = 0;
			rep(j, facnum) {
				if((1 << j) & k) {
					mul *= factor[n][j];
					b ++；
				}
			}
			if(b & 1) sum += cntExtend[mul];
			else sum -= cntExtend[mul];
		}
		ans += (LL)max(0, sum - 1) * (n - sum);
	}
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	Init_Primes();
	si(T);
	while(T --) {
		si(n);
		mem(has, 0);
		mem(fac, 0);
		mem(facn, 0);
		rep(i, n) si(a[i]), has[a[i]] = 1;
		getfactor();
	}
    
 
    return 0;
}