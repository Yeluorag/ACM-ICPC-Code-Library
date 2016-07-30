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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N][N], sum[N];
double p[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	mem(sum, 0);
    	for(int i = 1; i <= n; i ++) {
    		for(int j = 1; j <= m; j ++) 
    			si(a[i][j]), sum[i] += a[i][j];
    		for(int j = 1; j <= m; j ++)
    			p[i][j] = a[i][j] * 1.0 / sum[i];
    	}

    	double ans = 0.0;
    	for(int j = 1; j <= m; j ++) {
    		double tmp = 0.0;
    		for(int i = 1; i <= n; i ++) tmp += p[i][j];
    		tmp = tmp * tmp;
    		for(int i = 1; i <= n; i ++) 
    			tmp += p[i][j] - p[i][j] * p[i][j];
    		ans += tmp;
    	}
    	printf("%.2f\n", ans);
    }
    
    return 0;
}