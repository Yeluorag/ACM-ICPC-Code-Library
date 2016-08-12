// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 2e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
char input[10];
map<string, int > mp;
int dp[2*N], cnt[N], in[N], w[N], head[N], ne;
struct node {
    int v, nxt;
}e[N * N];
// Imp
void addEdge(int u, int v) {
    e[ne].v = v; e[ne].nxt = head[u]; head[u] =ne ++;
}

void dfs(int u) {
    int tmp[2*N];
    cnt[u] = 1;
    memcpy(tmp, dp, sizeof(dp));
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        dfs(v);
        cnt[u] += cnt[v];
    }
    for(int i = m + cnt[u]; i >= cnt[u]; i --) {
        Min(tmp[i], tmp[i-cnt[u]] + w[u]);
        Min(dp[i], tmp[i]);
    }
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(gets(input)) {
        if(input[0] == '#') break;
        stringstream inp(input);
        inp >> n, inp >> m;
        mp.clear();
        mem(dp, 0x3f);
        mem(cnt, 0);
        mem(in, 0);
        mem(head, -1);
        mem(w, 0);
        ne = 0;
        int tot = 0;
        FOR(i, 1, n) {
            string s;
            int t;
            getline(cin, s);
            stringstream ss;
            ss << s;
            ss >> s; ss >> t;
            if(!mp[s]) mp[s] = ++ tot;
            w[mp[s]] = t;
            int u = mp[s];
            while(1) {
                string str;
                ss >> str;
                if(ss.fail()) break;
                int k = mp[str];
                if(!k) {
                    mp[str] = ++ tot;
                    k = tot;
                }
                addEdge(u, mp[str]);
                in[k] ++;
            }
            ss.str("");
        } dp[0] = 0;
        FOR(i, 1, n) if(!in[i]) dfs(i);
        int ans = inf;
        FOR(i, m, 2 * n) Min(ans, dp[i]);
        put(ans);
    }
    
    return 0;
}