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
int n, m;

// Imp
bool isPrime(int n) {
	int m = sqrt(n + 0.5);
	FOR(i, 2, m) {
		if(n % i == 0) return false;
	}
	return true;
}
int cal(int n) {
	int m = sqrt(n + 0.5), ret = 0;
	FOR(i, 2, m) if(n % i == 0) {
		while(n % i == 0) {
			ret += i;
			n /= i;
		}
	}if(n > 1) ret += n;
	return ret;
}
int work(int n) {
	while(1) {
		if(isPrime(n)) return n;
		else {
			int t = cal(n);
			if(n == t) return -1;
			n = t;
		}
	}
	return -1;
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	printf("%d\n", work(n));
    }
    
    return 0;
}