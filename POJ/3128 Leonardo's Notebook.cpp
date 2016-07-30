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
const int inf = 0x3f3f3f3f, N = 30 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char s[N];
int a[N], vis[N], cnt[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%s", s);
    	n = strlen(s);
    	for(int i = 0; i < n; i ++) a[i] = s[i] - 'A';
    	mem(vis, 0), mem(cnt, 0);
    	for(int i = 0; i < 26; i ++) {
    		int j = i, ct = 0;
    		while(!vis[j]) {
    			vis[j] = 1, ct ++;
    			j = a[j];
    		} cnt[ct] ++;
    	}
    	bool ans = 1;
    	for(int i = 2; i <= 26; i += 2) 
    		if(cnt[i] & 1) ans = false;
    	printf("%s\n", ans ? "Yes" : "No");
    }
    
    return 0;
}