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
int n, ans, vis[N];
struct node{
    int sc, dl;
}a[N];
bool cmp(node a, node b) {
    if(a.sc == b.sc) return a.dl < b.dl;
    return a.sc > b.sc;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    cin >> T;
    while(T --) {
        si(n);
        rep(i, n) si(a[i+1].dl);
        rep(i, n) si(a[i+1].sc);
        ans = 0;
        mem(vis, 0);
        sort(a + 1, a + n + 1, cmp);
        FOR(i, 1, n) {
            int j;
            for(j = a[i].dl; j > 0; j --)
                if(!vis[j]) { vis[j] = 1; break; }
            if(!j) ans += a[i].sc;
        }
        printf("%d\n", ans);
    }
    
    
    return 0;
}