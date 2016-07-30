// Header.
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
const int inf = 0x3f3f3f3f, N = 5e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, c, sx, sy;
string maz;
vector<pair<int, int> > csm;

struct node {
    int x, y, cost;
};
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
// Imp

int bfs() {
    int ans = inf;
    queue<node> que;
    node st;
    map<pair<int, int>, int> mp;
    int flag = 0;
    st.x = sx, st.y = sy, st.cost = 0;
    que.push(st);
    while(!que.empty()) {
        node tmp = que.front(); que.pop();
        if(maz[tmp.x * m + tmp.y] == 'C') {
            ans = min(ans, tmp.cost);
            mp[make_pair(tmp.x, tmp.y)] = 0;
            continue;
        }
        node nxt;
        nxt.cost = tmp.cost;
        if(maz[tmp.x * m + tmp.y] == 'P' && !flag) {
            flag = 1;
            int sz = csm.size();
            rep(i, sz) {
                if(csm[i].first != tmp.x || csm[i].second != tmp.y) {
                    nxt.x = csm[i].first;
                    nxt.y = csm[i].second;
                    if(mp[make_pair(nxt.x, nxt.y)]) continue;
                    mp[make_pair(nxt.x, nxt.y)] = 1;
                    que.push(nxt);
                }
            }
        }
        rep(i, 4) {
            int nx = tmp.x + dx[i], ny = tmp.y + dy[i];
            if(nx < 0 || ny < 0 || nx >=n || ny >= m || maz[nx * m + ny] =='#' || mp[make_pair(nx, ny)]) continue;
            nxt.x = nx, nxt.y = ny, nxt.cost = tmp.cost;
            mp[make_pair(nx, ny)] = 1;
            if(maz[nx * m + ny] == '*') nxt.cost += c;
            que.push(nxt);
        }
    }
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(siii(n, m, c) != EOF) {
        csm.clear();
        maz.clear();
        char s[N];
        rep(i, n) {
            scanf("%s", s);
            maz += s;
        }
        rep(i, n * m) {
            if(maz[i] == 'P') csm.pb(make_pair(i / m, i % m));
            if(maz[i] == 'Y') sx = i / m, sy = i % m;
        }
        int ans = bfs();
        if(ans < inf) printf("%d\n", ans);
        else puts("Damn teoy!");
    } 
    
    return 0;
}