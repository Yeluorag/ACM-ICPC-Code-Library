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
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	LL sum = 0;
    	FOR(i, 1, n) { 
    		si(a[i]);
    		sum += (LL)a[i];
    	}
    	LL l = 0, r = sum, mid;
    	while(l <= r) {
    		mid = (l + r) >> 1;
    		LL tmp = 0;
    		FOR(i, 1, n) tmp += min((LL)a[i], mid);
    		if(tmp < mid * m) r = mid - 1;
    		else  l = mid + 1;
    	}
    	printf("%lld\n", r);
    }
    
    return 0;
}