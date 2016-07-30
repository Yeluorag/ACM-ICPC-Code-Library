#define LOCAL
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int s[N][N], d[N], len;
char a[N];

void init() {
	int l, r;
	mem(s, 0);
	FOR(i, 1, len) {
		for(int j = 0; i - j > 0 && i + j <= len; j ++) {
			l = i - j; r = i + j;
			if(a[l] == a[r]) s[l][r] = 1;
			else break;
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    cin >> T;
    while(T --) {
    	ss(a+1);
    	len = strlen(a+1);
    	d[0] = 1;
    	FOR(i, 1, len) {
    		rep(j, i) {
    			if(s[j+1][i]) d[i] = min(d[i], d[j] + 1);
    		}
    	} 
    	printf("%d\n", d[len]);
    }
    
    return 0;
}