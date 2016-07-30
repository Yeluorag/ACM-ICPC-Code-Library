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
const int inf = 1 << 30, N = 1e5 + 5, MOD = 1e9 + 7;

int n, m, isN = 0, ntN = 0, cnt = 0;
int a[N], is[N], nt[N], flag[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    mem(is, 0);
    mem(nt, 0);
    mem(flag, 0);
    sii(n, m);
    rep(i, n) {
    	si(a[i]);
    	if(a[i] > 0) isN ++, is[a[i]] ++;
    	else ntN ++, nt[-a[i]] ++;
    }
    FOR(i, 1, n)  if(is[i] - nt[i] + ntN  - m == 0) 
    	flag[i] = 1, cnt ++;
    rep(i, n) {
    	if(a[i] > 0 && !flag[a[i]]) puts("Lie");
    	else if(a[i] < 0 && flag[-a[i]] && cnt == 1) puts("Lie");
    	else if(a[i] > 0 && flag[a[i]] && cnt == 1) puts("Truth");
    	else if(a[i] < 0 && !flag[-a[i]]) puts("Truth");
    	else if(a[i] > 0 && flag[a[i]]) puts("Not defined");
    	else if(a[i] < 0 && flag[-a[i]]) puts("Not defined"); 	
    }
    
    return 0;
}