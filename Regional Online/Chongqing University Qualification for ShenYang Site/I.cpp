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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, tot, tmp;
map<string, int> sti;
set<int> stv[N];
char a[20], b[20], op[20];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(si(n) != EOF) {
        sti.clear();
        tot = 1;
        rep(i, n) stv[i].clear();
        rep(i, n) {
            scanf("%s", op);
            if(op[0] == 'a') {
                scanf("%s", a);
                si(m);
                if(!sti[a]) sti[a] = tot ++;
                int idx = sti[a];
                rep(j, m) {
                    si(tmp);
                    stv[idx].insert(tmp);
                }
            } else if(op[0] == 's') {
                scanf("%s", a);
                scanf("%s", b);
                int sa = sti[a], sb = sti[b];
                if(sa > sb) swap(sa, sb);
                if(sa == sb) continue;
                sti[b] = sti[a] = sa;
                set<int>:: iterator ite;
                for(ite = stv[sb].begin(); ite != stv[sb].end(); ite ++) {
                   	stv[sa].insert(*ite);
                }
            } else if(op[0] == 'c'){
                scanf("%s", a);
                int idx = sti[a];
                printf("%d", stv[idx].size());
            }
        }
        puts("");
    }
    
    return 0;
}