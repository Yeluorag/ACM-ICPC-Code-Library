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
const int inf = 0x3f3f3f3f, N = 2e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, idx, l, r;
char str[N], ans[N];
void solve() {
    while(l <= r) {
        bool left = false;
        for(int i = 0; l + i <= r; i ++) {
        	if(str[l + i] < str[r - i]) {
        		left = true;
        		break;
        	} else if(str[l + i] > str[r - i]) {
        		left = false;
        		break;
        	}
        }
        if(left) putchar(str[l ++]);
        else putchar(str[r --]);
    }
    putchar('\n');
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(n);
    for(int i = 0; i < n; i ++) {
        getchar();
        scanf("%c", &str[i]);
    }
    l = 0, r = n - 1;
    solve();
    
    return 0;
}