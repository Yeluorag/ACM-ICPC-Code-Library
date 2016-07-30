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
const int inf = 0x3f3f3f3f, N = 5e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, top;
int nxt[N], vis[N], pos[N];
char w[N], p[N];
char st[N];
// Imp

void get_next(char p[])  {
    int i = 0, j = -1;
    nxt[0] = -1;
    int len = strlen(p);
    while (i < len)  {
        if (j == -1 || p[i] == p[j]) {
            i++;
            j++;
            if (p[i] != p[j]) nxt[i] = j;
            else  nxt[i] = nxt[j];
        }
        else {
            j = nxt[j];
        }
    }
}

void index_kmp(char *p, char *x) {
    top = 0;
    int i = -1, j = -1, k = -1;
    int len1 = strlen(p), len2 = strlen(x);
    get_next(x);
    while(i < len1 && j < len2)  {
        if(i >=0 && !vis[i]) {
            vis[i] = 1;
            st[top ++] = p[i];
        }
        if (j == -1 || p[i] == x[j]) {
            j ++;
            pos[top - 1] = j;
            i ++;
        } else j = nxt[j];
        if (j == len2) {
            top -= j;
            j = pos[top - 1];
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(scanf("%s", w) != EOF) {
        mem(vis, 0);
        top = 0;
        scanf("%s", p);
        index_kmp(p, w);
        rep(i, top) printf("%c", st[i]);
        puts("");
    }
    
    return 0;
}