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
const LL MAX = 1e18;

int T, cas = 0;
int n, m;
LL l, r;
vector<LL> num;
vector<LL>::iterator ite;
// Imp
int len(LL n) {
	int ret = 0;
	while(n > 0) {
		n /= 10;
		ret ++;
	}
	return ret;
}

void add(LL n) {
	FOR(i, 2, 18) {
		if(len(n * i) == i) num.pb(n * i);
	}
}
void init() {
	num.clear();
	rep(i, 10) num.pb(i);
	rep(i, num.size()) {
		add(num[i]);
    }
    sort(ALL(num));
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    init();
    // rep(i, num.size()) cout << i + 1 << ":" <<  num[i] << endl;
    while(cin >> l >> r) {
    	
    	ite = lower_bound(ALL(num), l);
    	int L, R;
    	L = ite - num.begin();
    	ite = lower_bound(ALL(num), r);
    	R = ite - num.begin();
    	if(*ite == r) R ++;
    	cout << R - L << endl;
    }
    
    return 0;
}