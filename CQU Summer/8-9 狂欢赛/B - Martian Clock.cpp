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

char h[6],m[6],s[15];
map<char, int> mp;
VI ans;
void init() {
    ans.clear();
    rep(i, 10) mp[i + '0'] = i;
    rep(i, 26) mp[i + 'A'] = i + 10;
}

bool check(int b) {
    int ht = 0, mt = 0, k = 1;
    for(int i = strlen(h) - 1; i >= 0; i --){
        ht += mp[h[i]] * k;
        k *= b;
    } if(ht > 23) return false;
    k = 1;
    for(int i = strlen(m) - 1; i >= 0; i --){
        mt += mp[m[i]] * k;
        k *= b;
    } if(mt > 59) return false;
    return true;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    ss(s);
    int t = -1, len = strlen(s);
    rep(i, len) if(s[i] == ':') t = i;
    strncpy(h, s, t);
    strncpy(m, s + t + 1, len - t - 1);
    int Min_Base = -1;
    rep(i, len) {
        if(s[i] == ':') continue;
        Min_Base = max(Min_Base, mp[s[i]]);
    } Min_Base ++;
    int flag = 0;
    rep(i, strlen(h) - 1) if(h[i] != '0') flag = 1;
    rep(i, strlen(m) - 1) if(m[i] != '0') flag = 1;
    if(!flag) {
        if(mp[h[strlen(h)-1]] < 24) ans.pb(-1);
        else {
            for(int i = Min_Base; i < 200; i ++) {
                if(check(i)) ans.push_back(i);
                else break;
            }
        }
    } else {
        for(int i = Min_Base; i < 200; i ++) {
            if(check(i)) ans.push_back(i);
            else break;
        }
    }
    if((int)ans.size() == 0) printf("0\n");
    else {
        rep(i, ans.size() - 1) printf("%d ", ans[i]);
        printf("%d\n", ans[ans.size()-1]);
    }
    return 0;
}