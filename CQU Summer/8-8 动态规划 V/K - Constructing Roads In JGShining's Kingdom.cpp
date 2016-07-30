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
const int inf = 1 << 30, N = 5e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, ans, d[N];
struct node{
    int p, r;
}a[N];

bool cmp(node r, node s) { return r.p < s.p; }
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(si(n) != EOF) {
        ans = 0;
        rep(i, n) sii(a[i].p, a[i].r);
        sort(a, a + n, cmp);
        d[ans] = a[0].r;
        REP(i, 1, n) {
            if(a[i].r > d[ans]) d[++ans] = a[i].r;
            else {
                int ul = 0, ur = ans, mid;
                while(ul < ur) {
                    mid = (ul + ur) >> 1;
                    if(d[mid] < a[i].r) ul = mid + 1;
                    else ur = mid;
                }
                mid = ur;
                d[mid] = a[i].r;
            }
        }
        printf("Case %d:\n", ++ cas);
        if(!ans) printf("My king, at most %d road can be built.\n\n", ans + 1);
        else printf("My king, at most %d roads can be built.\n\n", ans + 1);
    }
    
    return 0;
}