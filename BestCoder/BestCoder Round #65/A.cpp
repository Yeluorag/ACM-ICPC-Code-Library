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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char a[N], b[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	int ans = 1;
    	si(n);
    	scanf("%s", a);
    	scanf("%s", b);
    	for(int i = 0; i < n; i ++) {
    		if(a[i] == 'A') {
    			if(b[i] != 'U') ans = 0;
    		}
    		if(a[i] == 'T') {
    			if(b[i] != 'A') ans = 0;
    		}
    		if(a[i] == 'C') {
    			if(b[i] != 'G') ans = 0;
    		}
    		if(a[i] == 'G') {
    			if(b[i] != 'C') ans = 0;
    		}
    	}
    	printf("%s\n", ans ? "YES" : "NO");

    }
    
    return 0;
}