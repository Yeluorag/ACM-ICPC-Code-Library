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
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30;
const int N = 300 + 5;

int n;
deque<int> a;
VI ans;

void Swap() { swap(a[0], a[1]); }

void Switch() {
    int t = a.back();
    a.pop_back();
    a.push_front(t);
}

bool check() {
    rep(i, n) if(a[i] != i + 1) return false;
    return true;
}

void solve() {
    while(!check()) {
        if(a[0] > a[1] && a[0] != n) { Swap(); ans.pb(1); }
        else { Switch(); ans.pb(2); }
    }
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(scanf("%d", &n), n) {
        ans.clear();
        a.clear();
        rep(i, n) {
            int t;
            scanf("%d", &t);
            a.pb(t);
        }
        
        solve();
        for(int i = ans.size() - 1; i >=0; i --) printf("%d", ans[i]);
        ET;
    }
    
    return 0;
}